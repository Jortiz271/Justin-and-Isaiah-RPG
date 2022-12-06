#pragma once
#include "Handler.h"
#include "entity.h"
#include "Functions.h"
#include "Button.h"
using namespace sf;

//Generators
void Engine::GenerateWindow(std::string title)
{
    float width, height;
    width = VideoMode::getDesktopMode().width;
    height = VideoMode::getDesktopMode().height;
    VideoMode vm(width, height);
    win.create(vm, title, sf::Style::Default);
}

void Engine::GenerateTextbox(std::string a, sf::Vector2f b, float sizex, float sizey, float Posx, float Posy)
{
    Font font;
    font.loadFromFile("fonts/PaladinFLF.ttf");
    Text textbox(a, font, 30);
    textbox.setFillColor(sf::Color::White);
    textbox.setScale(sizex, sizey);
    textbox.setPosition(Posx, Posy);
    DrawAll(textbox);
}

void Engine::GenerateBox(std::string title, sf::Vector2f b, float sizex, float sizey, float Posx, float Posy)
{
    // define a 120x50 rectangle
    sf::RectangleShape rectangle(sf::Vector2f(sizex, sizey));
    // change the size to 100x100
    rectangle.setPosition(Posx, Posy);
    rectangle.setSize(sf::Vector2f(b.x, b.y));
    rectangle.setFillColor(sf::Color::Cyan);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(3);
    rectangle.setScale(5, 5);
    DrawAll(rectangle);
    std::cout << "generated box" << std::endl;
}

void Engine::GenerateSprite(std::string fileName, sf::Vector2f b, float x, float y)
{
    Texture texture;
    texture.loadFromFile(fileName);
    Sprite sprite;
    sprite.setPosition(Vector2f(b.x, b.y));
    sprite.setScale(x, y);
    sprite.setTexture(texture);
    DrawAll(sprite);
}

//State
void Engine::FlipState()
{
    bool switched = false;
    if (now == UPDATING && !switched)
    {
        now = IDLING;
        switched = true;
        std::cout << "IDLING" << std::endl;
    }
    if (now == IDLING && !switched)
    {
        now = UPDATING;
        switched = true;
        std::cout << "UPDATING" << std::endl;
    }
}


//Engine Start
void Engine::EngineStart()
{
    //Pointers for the heap for player, enemey, and room
    Player* player = new Player;
    BasicEnemy* Enemy;
    
    //dungeon class
    int Floor = jAndIDungeon.getFloor();
    jAndIDungeon.fillDungeonWithRooms();
    Enemy = jAndIDungeon.CurrentEnemy;
    //main loop
    while (win.isOpen())
    {

        sf::Event evt;
        while (win.pollEvent(evt))
        {
            // Player input
            // Window closed
            if (evt.type == sf::Event::Closed)
                win.close();
            if (evt.type == sf::Event::KeyPressed)
            {
                if (evt.key.code == sf::Keyboard::Escape)
                {
                    win.close();
                }
            }
            if (evt.type == sf::Event::MouseButtonPressed)
            {
                if (evt.mouseButton.button == Mouse::Button::Left)
                {
                    Sounds.playSwordAttack();
                    cout << "Mouse pressed!" << evt.mouseButton.x << " " << evt.mouseButton.y << endl;
                    clicked.x = evt.mouseButton.x;
                    clicked.y = evt.mouseButton.y;
                    if (isAttackButtonPressed(clicked))
                    {
                        
                        //if the attack button is pressed, deal damage to the enemy based on the player's attack
                        Enemy->recieveDamage(player->dealDamage());
                        //if the attack kills the enemy, drop experience and then delete the enemy
                        //if the enemy is the last one in the room, call advance room, otherwise move on to the next enemy
                        if (Enemy->Dead())
                        {
                            std::cout << "Enemy Died ";
                            player->gainExp(Enemy->dropExperience());
                            jAndIDungeon.AdvanceRoom();
                            Enemy = jAndIDungeon.CurrentEnemy;
                            if (jAndIDungeon.finished) { win.close(); }
                        }

                    }
                }
            }
        }
        if (now == UPDATING)
        {
            UpdateWindow();
        }
    }
}

//draw functions
void Engine::DrawAll(Text a)
{
    win.draw(a);
}
void Engine::DrawAll(RectangleShape a)
{
    win.draw(a);
}
void Engine::DrawAll(Sprite a)
{
    win.draw(a);
}
void Engine::UpdateWindow()
{
    std::cout << "Updating Window" << std::endl;
    win.display();
    FlipState();
}
void Engine::ClearWindow()
{
    std::cout << "Clearing Window" << std::endl;
    win.clear();
}
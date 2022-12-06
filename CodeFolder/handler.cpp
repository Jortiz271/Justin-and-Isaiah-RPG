
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
    textbox.setFillColor(sf::Color::Black);
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
    GenerateTextbox(title,b,sizex,sizey,Posx,Posy);
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
    }
    if (now == IDLING && !switched)
    {
        now = UPDATING;
        switched = true;
    }
}
void Engine::AttackLogic()
{
    //if the attack button is pressed, deal damage to the enemy based on the player's attack
    if(!jAndIDungeon.CurrentRoom->isRestSite())
    {
jAndIDungeon.CurrentEnemy->recieveDamage(player.dealDamage());
    }

//if the attack kills the enemy, drop experience and then delete the enemy
//if the enemy is the last one in the room, call advance room, otherwise move on to the next enemy
if (jAndIDungeon.CurrentEnemy->Dead)
{
    win.clear();
    // sf::Sprite Background(jAndIDungeon.RandomRoomBackground());
    // win.draw(Background);
    Texture background;
    background.loadFromFile("graphics/dungeon1.jpg");
    sf::Sprite DungeonBackground(background);
    DungeonBackground.setOrigin(0,0);
    DungeonBackground.setScale(4,3);
    win.draw(DungeonBackground);
    Sprite Player(player.getSprite());
    Texture EnemyTexture;
    EnemyTexture.loadFromFile("graphics/monstergoo.png");
    Sprite EnemySp(EnemyTexture);
    EnemySp.setScale(.45,.45);
    Player.setPosition(Vector2f(600,300));
    win.draw(Player);
    win.draw(EnemySp);
    GenerateBox("Attack",sf::Vector2f(75,25),100,100,300,600);
    win.display();
    player.gainExp(jAndIDungeon.CurrentEnemy->dropExperience());
    jAndIDungeon.AdvanceRoom();
    // sf::Sprite EnemySprite(jAndIDungeon.CurrentEnemy->generateTexture());
    // win.draw(EnemySprite);
  
    if(jAndIDungeon.HealthToAward != 0)
    {
        player.setHealth(player.GetHealth() + jAndIDungeon.HealthToAward);
        jAndIDungeon.HealthToAward = 0;
    }
    Enemy = jAndIDungeon.CurrentEnemy;
    if (jAndIDungeon.finished) 
    {
        sf::Texture winscreen;
        winscreen.loadFromFile("graphics/winscreen.jpg");
        sf::Sprite WinningScreen(winscreen);
        win.clear();
        win.draw(WinningScreen);
        win.display();
    }
}
else
{
player.recieveDamage(Enemy->dealDamage());
if(player.Dead)
{
    player.Deaded();
    win.draw(player.getSprite());
    win.display();
}
}

}
void Engine::Bootstrap()
{
    //dungeon class
    jAndIDungeon.fillDungeonWithRooms();
}
//Engine Start
void Engine::EngineStart()
{
    //Pointers for the heap for player, enemey, and room
    Bootstrap();
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
                    clicked.x = evt.mouseButton.x;
                    clicked.y = evt.mouseButton.y;
                    if (isAttackButtonPressed(clicked))
                    {
                        AttackLogic();
                        
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
    win.display();
    FlipState();
}
void Engine::ClearWindow()
{
    win.clear();
}
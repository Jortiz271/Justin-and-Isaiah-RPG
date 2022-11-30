#include "Handler.h"
using namespace sf;
void Engine::GenerateWindow(std::string title)
{
    float width, height;
    width = VideoMode::getDesktopMode().width;
    height = VideoMode::getDesktopMode().height;
    VideoMode vm(width, height);
    win.create(vm, title, sf::Style::Default);
}
void Engine::GenerateTextbox(std::string a, sf::Vector2f b) const
{
    Font font;
    font.loadFromFile("/home/admin/Desktop/rpg/Justin-and-Isaiah-RPG/fonts/PaladinFLF.ttf");
    Text textbox(a, font, 10);
    textbox.setFillColor(sf::Color::White);
    textbox.setOutlineColor(sf::Color::White);
    textbox.setScale(1, 1);
    textbox.setPosition(b.x, b.y);
    DrawAll(textbox);
}
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
void Engine::EngineStart()
{
    while (win.isOpen())
    {
        sf::Event evt;
        while (win.pollEvent(evt))
        {
            // Window closed
            if (evt.type == sf::Event::Closed)
                win.close();
            if (evt.type == sf::Event::MouseButtonPressed)
            {
                if (evt.mouseButton.button == Mouse::Button::Left)
                {
                    UpdateWindow();
                }
            }
        }
        if (now == UPDATING)
        {
            UpdateWindow();
        }
    }
}
template <typename T>
void Engine::DrawAll(T a) const
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
void Engine::GenerateBox(std::string title, sf::Vector2f b) const
{
    if(title == "BaseUI")
    {
        sf::RectangleShape rect(Vector2f(1920,1080/2));
        rect.setPosition(Vector2f(0,1080/2));
        rect.setFillColor(sf::Color::Green);
        DrawAll(rect);
    }
    sf::RectangleShape rect(Vector2f(50,50));
    rect.setPosition(Vector2f(b.x, b.y));
    rect.setFillColor(sf::Color::Red);
    DrawAll(rect);
    GenerateTextbox(title, Vector2f(b.x + 5,b.y + title.length()));
}
void Engine::GenerateSprite(std::string fileName, sf::Vector2f b) const
{
    Texture texture;
    texture.loadFromFile(fileName);
    Sprite sprite;
    sprite.setPosition(Vector2f(b.x, b.y));
	sprite.setScale(4,1.5);
    sprite.setTexture(texture);
    DrawAll(sprite);
}
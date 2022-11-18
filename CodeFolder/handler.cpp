#include "Handler.h"
using namespace sf;
void Engine::GenerateWindow(std::string title)
{
win.create(sf::VideoMode(1920,1080,32),title);
}
void Engine::GenerateTextbox(std::string a,sf::Vector2i b)
{
Font font;
font.loadFromFile("fonts/PaladinFLF.ttf");
Text textbox;
textbox.setString(a);
textbox.setFont(font);
textbox.setFillColor(sf::Color::White);
textbox.setOutlineColor(sf::Color::Black);
textbox.setScale(1,1);
textbox.setStyle(sf::Text::Bold);
textbox.setPosition(b.x,b.y);
win.draw(textbox);
FlipState(now);
}
void Engine::FlipState(Engine::CurrentState a)
{
    if(a == Engine::CurrentState::UPDATING)
    {
        a = Engine::CurrentState::IDLING;
    }
    else
    {
        a = Engine::CurrentState::UPDATING;
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

        // Escape key pressed
        if ((evt.type == sf::Event::KeyPressed) && (evt.key.code == sf::Keyboard::Escape))
            win.close();
    }
    if(Engine::now == Engine::CurrentState::UPDATING)
    {
        win.display();
        FlipState(now);
    }
}
}
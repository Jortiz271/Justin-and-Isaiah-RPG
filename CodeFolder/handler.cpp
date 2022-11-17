#include "Handler.h"
using namespace sf;
RenderWindow GenerateWindow(std::string a)
{
VideoMode res(1920, 1080);
VideoMode mon = res.getDesktopMode();
return RenderWindow win(mon,a,sf::Style::Default);
}
void Engine::GenerateTextbox(std::string a,sf::Vector2i b)
{
Font font;
font.loadFromFile("rpg/fonts/PaladinFLF.ttf");
Text textbox;
textbox.setString(a);
textbox.setFont(font);
textbox.setFillColor(sf::Color::White);
textbox.setOutlineColor(sf::Color::Black);
textbox.setScale(1,1);
textbox.setStyle(sf::Text::Bold);
textbox.setPosition(b.x,b.y);
win->draw(textbox);
FlipState();
}
void FlipState(Engine::CurrentState a)
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
void EngineStart()
{

}
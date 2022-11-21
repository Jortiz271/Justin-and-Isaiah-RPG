#include "Handler.h"
using namespace sf;
void Engine::GenerateWindow(std::string title)
{
   float width, height;
	width = VideoMode::getDesktopMode().width;
	height = VideoMode::getDesktopMode().height;
	VideoMode vm(width, height); 
win.create(vm,title,sf::Style::Default);
}
void Engine::GenerateTextbox(std::string a,sf::Vector2i b)
{
Font font;
font.loadFromFile("/home/admin/Desktop/rpg/Justin-and-Isaiah-RPG/fonts/PaladinFLF.ttf");
Text textbox(a,font,10);
textbox.setFillColor(sf::Color::White);
textbox.setOutlineColor(sf::Color::White);
textbox.setScale(1,1);
textbox.setPosition(b.x,b.y);
DrawAll(textbox);
}
void Engine::FlipState()
{
    bool switched = false;
    if(now == UPDATING && !switched)
    {
        now = IDLING;
        switched = true;
        std::cout << "Idling" << std::endl;
    }
    if(now == IDLING && !switched)
    {
        now = UPDATING;
        switched = true;
        std::cout << "Updating" << std::endl;
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
        if(evt.type == sf::Event::MouseButtonPressed)
    {
        Engine::GenerateTextbox("Hello World",Vector2i(Mouse::getPosition().x,Mouse::getPosition().y));
    }
    }
    if(now == UPDATING)
    {
        std::cout << "EngineUpdate" << std::endl;
        UpdateWindow();
    }
    
}
}
template<typename T>
void Engine::DrawAll(T a)
{
    std::cout << "drawing all objects" << std::endl;
win.draw(a);
UpdateWindow();
}
void Engine::UpdateWindow()
{
 std::cout << "updatingWindow" << std::endl;

    win.display();
    FlipState();
}
void Engine::ClearWindow(sf::RenderWindow window)
{
win.clear();
}
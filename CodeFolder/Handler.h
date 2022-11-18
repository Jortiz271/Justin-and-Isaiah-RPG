#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Engine
{
public:
Engine()
{
    now = IDLING;
}
enum CurrentState { UPDATING, IDLING };
CurrentState now;
void GenerateWindow(std::string title);
void GenerateTextbox(std::string a,sf::Vector2i b);
void FlipState(CurrentState);
void EngineStart();
sf::RenderWindow win;
};
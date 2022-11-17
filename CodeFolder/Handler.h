#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Engine
{
public:
enum CurrentState { UPDATING, IDLING };
CurrentState now;
RenderWindow GenerateWindow();
void GenerateTextbox(std::string a,sf::Vector2i b);
void FlipState();
void EngineStart();
std::string SetWindowName(std::string a);
RenderWindow* win = &GenerateWindow();
};
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Engine
{
public:
Engine()
{
    now = UPDATING;
}
enum CurrentState { UPDATING, IDLING };
CurrentState now;
void GenerateWindow(std::string title);
void GenerateTextbox(std::string a,sf::Vector2f b);
void GenerateBox(std::string title, sf::Vector2f b);
void GenerateSprite(std::string fileName,sf::Vector2f b);
void FlipState();
template<typename T>
void DrawAll(T a);
void ClearWindow(sf::RenderWindow window);
void EngineStart();
void UpdateWindow();
sf::RenderWindow win;
};
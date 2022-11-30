#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
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
void GenerateTextbox(std::string a,sf::Vector2f b) const;
void GenerateBox(std::string title, sf::Vector2f b) const;
void GenerateSprite(std::string fileName,sf::Vector2f b) const;
void FlipState();
template<typename T>
void DrawAll(T a) const;
void ClearWindow();
void EngineStart();
void UpdateWindow();
sf::RenderWindow win;
};
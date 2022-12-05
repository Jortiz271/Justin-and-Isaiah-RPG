#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>
#include <vector>
//Class that is used to store states, window, sprites, textbox, functions to draw/clear window,
class Engine
{
    public:
    Engine()
    {
        now = UPDATING;
    }
    //variables
    enum CurrentState { UPDATING, IDLING };
    CurrentState now;
    sf::Vector2f clicked;
    sf::RenderWindow win;
    //functions
    void GenerateWindow(std::string title);
    void GenerateTextbox(std::string a,sf::Vector2f b, float sizex, float sizey, float Posx, float Posy);
    void GenerateBox(std::string title, sf::Vector2f b, float sizex, float sizey, float Posx, float Posy);
    void GenerateSprite(sf::Sprite* texture, float posx, float posy, float x, float y);
    void FlipState();
    //overloaded draws fixed the errors I was having.
    void DrawAll(sf::Text a);
    void DrawAll(sf::Sprite* a);
    void DrawAll(sf::RectangleShape a);
    void ClearWindow();
    void EngineStart();
    void UpdateWindow();
};
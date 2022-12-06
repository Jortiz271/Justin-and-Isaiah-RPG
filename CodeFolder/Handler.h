#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "BasicEnemy.h"
#include "dungeon.h"
#include "Functions.h"
#include "SoundManager.h"
using namespace sf;
using namespace std;
//Class that is used to store states, window, sprites, textbox, functions to draw/clear window,
class Engine
{
public:
    inline Engine()
    {
        now = UPDATING;
        GenerateWindow("Tales of Fire and Flames");
    }

    //variables
    enum CurrentState { UPDATING, IDLING };
    CurrentState now;
    sf::Vector2f clicked;
    sf::RenderWindow win;
    Player* player;
    BasicEnemy* Enemy;
    Dungeon jAndIDungeon;
    SoundManager Sounds;

    //functions
    void Bootstrap();
    void GenerateWindow(std::string title);
    void GenerateTextbox(std::string a, sf::Vector2f b, float sizex, float sizey, float Posx, float Posy);
    void GenerateBox(std::string title, sf::Vector2f b, float sizex, float sizey, float Posx, float Posy);
    void GenerateSprite(std::string fileName, sf::Vector2f b, float scalex, float scaley);
    void FlipState();
    //overloaded draws fixed the errors I was having.
    void DrawAll(sf::Text a);
    void DrawAll(sf::Sprite a);
    void DrawAll(sf::RectangleShape a);
    void ClearWindow();
    void EngineStart();
    void UpdateWindow();
};
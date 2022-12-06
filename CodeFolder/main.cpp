#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "Handler.h"
#include <vector>
using namespace sf;
//FYI I DID CHANGE THE FILES PATHS BECAUSE IT DID NOT WORK ON MY COMP YOU MAY NEED TO CHANGE THEM BACK FOR IT TO WORK WITH YOU SETUP
//Still need death logic to erase enemies when beaten and move to next floor
//Death Rules for player when they die what happens????
//Win conditions in dungeon.cpp are not finnished Maybe we can get some cool graphics and some victory sounds
//still need logic in handler that uses 
int main()
{
	sf::Music music;
	if (!music.openFromFile("sound/MainMusic.wav"))
		return -1; // error
	music.play();
	Engine handler;
	handler.GenerateWindow("Tales of Flame and Fire");
	handler.GenerateSprite("graphics/dungeon1.jpg", Vector2f(50,50),6,5);
	handler.GenerateSprite("graphics/player.png",Vector2f(1700, 600),1,1);
	handler.GenerateSprite("graphics/monstergoo.png",Vector2f(300, 600),1,1);
	handler.GenerateBox("attack",sf::Vector2f(75,25),100,100,300,1400);
	handler.GenerateTextbox("Attack!", sf::Vector2f(100, 100),3, 3,340,1400);
	handler.EngineStart();
}

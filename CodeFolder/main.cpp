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
	handler.EngineStart();
}

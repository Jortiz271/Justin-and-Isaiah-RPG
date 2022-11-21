#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Handler.h"
using namespace sf;

int main()
{
Engine handler;
std::cout << handler.now << std::endl;
handler.GenerateWindow("Tales of Flame and Fire");
handler.GenerateTextbox("It just works",Vector2f(1920/2,1080/2));
handler.GenerateSprite("/home/admin/Desktop/rpg/Justin-and-Isaiah-RPG/graphics/dungeon1.jpg",Vector2f(0,0));
handler.EngineStart();
}

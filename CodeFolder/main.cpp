#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Handler.h"
using namespace sf;
//test
int main()
{
Engine handler;
handler.GenerateWindow("Tales of Flame and Fire");
handler.GenerateBox("Battle Log",Vector2f(1920/2,1080/2));
handler.GenerateSprite("/home/admin/Desktop/rpg/Justin-and-Isaiah-RPG/graphics/dungeon1.jpg",Vector2f(0,0));
handler.EngineStart();
}

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
handler.GenerateBox("BaseUI",Vector2f(0,0));
handler.GenerateBox("Cast",Vector2f(1920/4,1080/2));
handler.GenerateBox("Attack",Vector2f(0,1080/2));
handler.GenerateBox("Heal",Vector2f(1920/2,1080/2));
handler.GenerateBox("Advance\nRoom",Vector2f(1920 - 128,1080/2));
handler.GenerateSprite("/home/admin/Desktop/rpg/Justin-and-Isaiah-RPG/graphics/dungeon1.jpg",Vector2f(0,0));
handler.GenerateSprite("/home/admin/Desktop/rpg/Justin-and-Isaiah-RPG/graphics/player.png",Vector2f(1920*.75,75),.45,.45);
handler.GenerateSprite("/home/admin/Desktop/rpg/Justin-and-Isaiah-RPG/graphics/monstergoo.png",Vector2f(0,75),.45,.45);
handler.EngineStart();
}

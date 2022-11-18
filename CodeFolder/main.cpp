#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Handler.h"
using namespace sf;

int main()
{
Engine handler;
handler.GenerateWindow("Tales of Flame and Fire");
handler.GenerateTextbox("Test this for the love of god just work work work work work",Vector2i(1920/2,1080/2));
handler.EngineStart();
}

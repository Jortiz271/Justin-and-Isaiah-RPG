#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Handler.h"
using namespace sf;

int main()
{
Engine handler;
handler.GenerateTextbox("Test",Vector2i(0,0));
handler.EngineStart();
handler.FlipState();

}

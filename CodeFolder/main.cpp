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
handler.EngineStart();
}

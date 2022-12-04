#pragma once
#include "Handler.h"
#include "SFML/Audio.hpp"
#include <string>
//Bugged Button wont render properly for some reason I think it has to do with  inheritance or it isn't vibing with handler or somehing
class Buttons : public Engine
{

public:

	void createButton();
	Buttons();
	void GenerateButton(float buttonSizex, float buttonSizey, float buttonPositionx, float buttonPositiony, std::string Text);
	bool isPressed(int mousex, int mousey);
	void makeSound();

private:
	float buttonSizeX = 100, buttonSizeY = 50, buttonPositionX = 0, buttonPositionY = 0;
	std::string buttonText = "";
};

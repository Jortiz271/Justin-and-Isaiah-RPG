
#include "Button.h"
#include <string>

//constructors
Buttons::Buttons()
{
	float buttonSizeX = 100, buttonSizeY = 50, buttonPositionX = 0, buttonPositionY = 0;
	std::string buttonText = "";
}

void Buttons::GenerateButton(float buttonSizex, float buttonSizey, float buttonPositionx, float buttonPositiony, std::string Text)
{
	Engine::GenerateTextbox(Text, sf::Vector2f(buttonPositionx, buttonPositiony), buttonSizex, buttonSizey,buttonPositionX,buttonPositionY);
	Engine::GenerateBox(Text, sf::Vector2f(buttonPositionx, buttonPositiony), buttonSizex, buttonSizey,buttonPositionX,buttonPositionY);
	std::cout << "Button Created" << std::endl;
}

//PlaySound when button is Pressed
void Buttons::makeSound()
{
	
}

//Checks Position of Mouse click and sees if it is within bounds of button. Then Pla
bool Buttons::isPressed(int mousex, int mousey)
{
	//this is wrong. Need to finnish
	if(mousex >1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Buttons::createButton()
{
	float buttonSizeX = 100, buttonSizeY = 50, buttonPositionX = 0, buttonPositionY = 0;
	std::string buttonText = "";
	//Engine::GenerateBox(this->buttonText, sf::Vector2f(this->buttonPositionX, this->buttonPositionY), this->buttonSizeX, this->buttonSizeY);
	//Engine::GenerateTextbox(this->buttonText,sf::Vector2f(this->buttonPositionX,this->buttonPositionY),this->buttonSizeX, this->buttonSizeY);
	
}
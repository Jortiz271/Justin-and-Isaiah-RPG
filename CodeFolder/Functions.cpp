#include "Functions.h"
#include <iostream>
bool isAttackButtonPressed(sf::Vector2f clicked)
{
	std::cout << clicked.x << " " << clicked.y << std::endl;
	std::cout << "Used";
	if (clicked.x > 297 && clicked.x < 675 && clicked.y > 1392 && clicked.y < 1527)
	{
		return true;
	}
	return false;
}
void attackButtonLogic()
{
	std::cout << "Attack Logic" << std::endl;
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("sound/SwordAttack.wav"))
		std::cout << "Sound Wont Load" << std::endl;
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
}

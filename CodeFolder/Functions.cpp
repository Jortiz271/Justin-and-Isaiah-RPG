#include "Functions.h"
#include <iostream>
bool isAttackButtonPressed(sf::Vector2f clicked)
{
	if (clicked.x > 297 && clicked.x < 675 && clicked.y > 600 && clicked.y < 800)
	{
		return true;
	}
	return false;
}
void attackButtonLogic()
{
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("sound/SwordAttack.wav"))
		std::cout << "Sound Wont Load" << std::endl;
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
}

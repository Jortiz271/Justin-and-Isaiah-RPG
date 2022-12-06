#include "Functions.h"
#include <iostream>
<<<<<<< HEAD
=======
#include "SoundManager.h"S
>>>>>>> 8833a5d90aa2614f4723e0bde53ac9498d7d74dc
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
<<<<<<< HEAD
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("sound/SwordAttack.wav"))
		std::cout << "Sound Wont Load" << std::endl;
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
}
=======
	
}
>>>>>>> 8833a5d90aa2614f4723e0bde53ac9498d7d74dc

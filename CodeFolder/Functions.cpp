#include "Functions.h"
#include <iostream>
#include "SoundManager.h"S
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
	
}
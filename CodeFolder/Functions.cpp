#include "Functions.h"
#include <iostream>

bool isAttackButtonPressed(sf::Vector2i clicked)
{
	sf::IntRect r1(300, 1400, 300, 150);

	if (r1.contains(clicked))
	{
		return true;
	}
	return false;
}
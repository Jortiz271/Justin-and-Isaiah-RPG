#include "BasicEnemy.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

BasicEnemy::BasicEnemy()
{
	Entity::setAttack(15);
	Entity::setHealth(100);
	Entity::setlevel(1);
	enemySprite = BasicEnemy::generateSprite();
}

int BasicEnemy::dropExperience()
{
	return 10 * Entity::getLevel();
}

//Generates one of 3 enemies randmoly for our sprite
Sprite BasicEnemy::generateSprite()
{
	Texture Monster;
	Texture Monster2;
	Texture Boss;

	Monster.loadFromFile("graphics/monster_eyeball.png");
	Monster2.loadFromFile("graphics/monstergoo.png");
	Boss.loadFromFile("graphics/Boss.png");

	Sprite spriteMonster;
	spriteMonster.setTexture(Monster);
	Sprite spriteMonster2;
	spriteMonster2.setTexture(Monster2);
	Sprite spriteBoss;
	spriteBoss.setTexture(Boss);
	
	// Use current time as seed for random generator
	srand(time(0));
	int randomSelection = (rand() % 3) + 1;
	if (randomSelection == 1)
	{
		return spriteBoss;
	}
	else if (randomSelection == 2)
	{
		return spriteMonster;
	}
	else
	{
		return spriteMonster2;
	}
}

//Constructor
BasicEnemy::BasicEnemy(int CurrFloor,bool Modifiable)
{
	Entity::setHealth((CurrFloor + 1 * 50));
	Entity::setAttack(15);
	Entity::setlevel(1);
	generateSprite();
}

int BasicEnemy::dealDamage(int CurrFloor)
{
	return (1.5 + CurrFloor * getAttack());
}
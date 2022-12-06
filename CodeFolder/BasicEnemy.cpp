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
<<<<<<< HEAD
BasicEnemy::BasicEnemy(int CurrentFloor,bool Modifiable)
=======
BasicEnemy::BasicEnemy(int CurrentFloor, bool Modifiable)
>>>>>>> 8833a5d90aa2614f4723e0bde53ac9498d7d74dc
{
	Entity::setHealth((CurrFloor + 1 * 50));
	Entity::setAttack(15);
	Entity::setlevel(1);
	generateSprite();
	CurrFloor = CurrentFloor;
}

int BasicEnemy::dealDamage()
{
	return (1.5 + CurrFloor * getAttack());
}
void BasicEnemy::Deaded()
{
<<<<<<< HEAD
	if(Dead)
=======
	if (Entity::Dead())
>>>>>>> 8833a5d90aa2614f4723e0bde53ac9498d7d74dc
	{
		std::cout << "successfully deleted Enemy";
		sf::Texture DeadText;
		DeadText.loadFromFile("graphics/PlayerDead.jpg");
		enemySprite.setTexture(DeadText);
<<<<<<< HEAD
		
=======

>>>>>>> 8833a5d90aa2614f4723e0bde53ac9498d7d74dc
	}
}
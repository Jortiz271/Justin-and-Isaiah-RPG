#include "BasicEnemy.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
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
	// Use current time as seed for random generator
	srand(time(0));
	int randomSelection = (rand() % 3) + 1;
	if (randomSelection == 1)
	{
		enemySprite.setPosition(Vector2f(300, 600));
		enemySprite = Sprite(TextureHolder::GetTexture("graphics/monster_eyeball.png"));
		return enemySprite;
	}
	else if (randomSelection == 2)
	{
		enemySprite.setPosition(Vector2f(300, 600));
		enemySprite = Sprite(TextureHolder::GetTexture("graphics/monstergoo.png"));
		return enemySprite;
	}
	else
	{
		enemySprite.setPosition(Vector2f(300, 600));
		enemySprite = Sprite(TextureHolder::GetTexture("graphics/Boss.png"));
		return enemySprite;
	}
}

//Constructor
BasicEnemy::BasicEnemy(int CurrentFloor, bool Modifiable)
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
	if (Entity::Dead())
	{
		std::cout << "successfully deleted Enemy";
		sf::Texture DeadText;
		DeadText.loadFromFile("graphics/PlayerDead.jpg");
		enemySprite.setTexture(DeadText);

	}
}
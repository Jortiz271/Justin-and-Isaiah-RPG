#include "BasicEnemy.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
vector<pair<string,int>> BasicEnemy::dropLoot()
{
	vector<pair<string,int>> Loot;
	Loot.push_back(this->armor);
	Loot.push_back(this->weapon);
	return Loot;
}

int BasicEnemy::dropExperience()
{
	return 10 * Level;
}
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
	
	spriteMonster.setScale(0.75, 0.75);
	spriteMonster.setPosition(800, 800);

	spriteMonster2.setScale(0.75, 0.75);
	spriteMonster2.setPosition(800, 800);

	spriteBoss.setScale(1.0, 1.0);
	spriteBoss.setPosition(800, 800);
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
BasicEnemy::BasicEnemy(int CurrFloor,bool Modifiable)
{
	Health = CurrFloor * 3;
	if(Modifiable)
	{
		Attack = CurrFloor * 3;
	}
	else
	{
		Attack = CurrFloor;
	}
};
Boss::Boss(int CurrFloor,bool Modifiable)
{
Health = CurrFloor * 5;
if(Modifiable)
{
	Attack = CurrFloor * 7;
}
else
{
Attack = CurrFloor * 5;
}
}
void BasicEnemy::DealDamage(Entity* opponent)
{
	if(Attack > opponent->Defense)
	{
		opponent->SetHealth(Attack - opponent->Defense);
	}
}
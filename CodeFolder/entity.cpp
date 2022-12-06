#include "entity.h"
#include "Handler.h"
int Entity::GetHealth()
{
	return Health;
}
void Entity::setHealth(int hp)
{
	this->Health = hp;
}

int Entity::getLevel()
{
	return this->Level;
}
void Entity::setlevel(int lvl)
{
	this->Level = lvl;
}
int Entity::getAttack()
{
	return Attack;
}
void Entity::setAttack(int att)
{
	this->Attack = att;
}
void Entity::recieveDamage(int dmg)
{
	this->Health = this->Health - dmg;
	if(Health < 0)
	{
		Dead = true;
	}
}
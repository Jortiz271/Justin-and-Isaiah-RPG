#include "Player.h"

bool Player::canCast(int mpCost)
{
	if (mpCost > this->mana)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

// what is this for?????
//was gonna try and use one function declaration to handle casting spells and attacking with sword
void Player::dealMagicDamage()
{
	
}
void Player::dealDamage()
{
	
}

void Player::setEquipment(string item)
{
	this->armor = item;
}

int Player::getHealth()
{
	return this->getHealth();
}

void Player::setHealth(int HP)
{
	this->setHealth(HP);
}

int Player::getMana()
{
	return this->mana;
}

void Player::setMana(int MP)
{
	this->mana = MP;
}
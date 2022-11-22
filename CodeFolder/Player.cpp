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
bool Player::dealDamage(bool attking)
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
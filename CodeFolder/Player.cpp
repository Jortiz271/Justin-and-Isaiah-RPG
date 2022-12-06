#include "Player.h"
//constructor loads a sprite to be associated with the class
Player::Player()
{
	PlayerTexture.loadFromFile("graphics/player.png");
	playerSprite.setTexture(PlayerTexture);
}
int Player::dealDamage()
{
	return Entity::getAttack() + exp;
}
Sprite Player::getSprite()
{
	return playerSprite;
}
void Player::gainExp(int expGain)
{
	this->exp = this->exp + expGain;

}
void Player::Deaded()
{
	if(Dead)
	{
		PlayerTexture.loadFromFile("graphics/playerDead.png");
		playerSprite.setTexture(PlayerTexture);
	}
}

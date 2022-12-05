#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include "entity.h"
#include <iostream>
using namespace std;
using namespace sf;
class Player : public Entity
{
private:
	Sprite playerSprite;
	Texture PlayerTexture;
	//needs function for Ui showing current player health
	Text HpText;
	int exp = 0;
public:
	Player();
	void gainExp(int expGain);
	void Deaded() override;
	int dealDamage() override;
	Sprite getSprite();
};
#endif
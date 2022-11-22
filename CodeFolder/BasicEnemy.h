#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "Entity.h"
using namespace std;
class BasicEnemy : public Entity
{
private:
	string armor;
	string weapon;
public:
	string dropLoot();
	int dropExperience();
	Sprite generateSprite();
};
#endif
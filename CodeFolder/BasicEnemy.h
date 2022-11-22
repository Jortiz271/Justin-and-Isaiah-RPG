#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "entity.h"
using namespace std;
class BasicEnemy : public Entity
{
protected:
	pair<string,int> armorEquip;
	pair<string,int> weaponEquip;
public:
	vector<pair<string,int>> dropLoot();
	int dropExperience();
	sf::Sprite generateSprite();
};
class Boss : BasicEnemy
{
public:
void isInviincible(int);
private:
int TurnCounter;
bool invincibility;
string prefix;
};
#endif
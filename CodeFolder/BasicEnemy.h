#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "entity.h"
using namespace std;
class BasicEnemy : public Entity
{

public:
	vector<pair<string,int>> dropLoot();
	int dropExperience();
	sf::Sprite generateSprite();
	BasicEnemy(int,bool);
	pair<string,int> armor;
	pair<string,int> weapon;
	void DealDamage(Entity*);
	inline BasicEnemy()
	{
		armor = std::make_pair(std::string("Shield"),2);
		weapon = std::make_pair(std::string("Sword"),2);


	}
	~BasicEnemy()
	{

	}
};
class Boss : public BasicEnemy
{
public:
void isInviincible(int);
private:
int TurnCounter;
bool invincibility;
string prefix;
inline Boss()
{
	TurnCounter = 0;
	invincibility = false;
	prefix = "Magnificent";
};
Boss(int,bool);
};
#endif
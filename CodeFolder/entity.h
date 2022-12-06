#pragma once
#include <string>
#include <utility>
#include <set>
using namespace std;
//Basic Class that holds the values and behaviour for monsters and player
class Entity
{
public:
	bool Dead;
	virtual void Deaded() = 0;
	int GetHealth();
	void setHealth(int hp);
	int getLevel();
	void setlevel(int lvl);
	int getAttack();
	void setAttack(int att);
	virtual int dealDamage() = 0;
	void recieveDamage(int dmg);

private:
	int Health;
	int Attack;
	int Level;
};
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;
class Player
{
private:
	string armor;
	string weapon;
	string magic;
	int mana;
	int exp;
	int healthPotions;
public:
	bool canCast(int mpCost);
	void dealDamage();
	void dealMagicDamage();
	void setEquipment(string item);
	int getHealth();
	void setHealth(int HP);
	int getMana();
	void setMana(int MP);
};
#endif
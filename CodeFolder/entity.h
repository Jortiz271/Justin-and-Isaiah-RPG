#pragma once
#include <string>
#include <utility>
#include <set>
#include "Handler.h"
using namespace std;
class Entity : public Engine
{
public:
int Health;
int Attack;
int Defense;
int Level;
bool Dead;
string AttackType;
set<pair<string,int>> equipment;
void virtual DealDamage(Entity*) = 0;
int GetHealth();
void virtual SetHealth(int);
int GetDefense();
void SetDefense(pair<string,int> armor);
enum EquipType
{
    armorEquip,weaponEquip,spellEquip
};
EquipType itemType;
~Entity()
{

};
};
class Player : public Entity
{
private:
int mana,experience,healthPotions;
pair<string,int> spell;
public:
bool CanCast(int);
void DealDamage(bool,Entity*);
void SetEquipment(pair<string,int> thing,EquipType);
void SetHealth(int,int);
int GetMana();
void SetMana(int);
};
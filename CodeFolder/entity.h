#pragma once
#include <string>
#include <utility>
#include <set>
using namespace std;
class Entity
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
public:
int mana,experience,healthPotions;
pair<string,int> spell;
bool CanCast(int);
void DealDamage(Entity*) override;
void SetEquipment(pair<string,int> thing,EquipType);
void SetHealth(int,int);
int GetMana();
void SetMana(int);
inline Player()
{
    mana = 12;
    experience = 0;
    healthPotions = 6;
    spell.first = "fireball";
    spell.second = 3;
    Defense = 2;
    Attack = 2;

}
};
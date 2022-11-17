#include <string>
#include <utility>
#include <set>
using namespace std;
class Entity
{
protected:
int Health;
int Attack;
int Defense;
int Level;
bool Dead;
string AttackType;
pair<string,int> armor;
pair<string,int> weapon;
pair<string,int> spell;
set<pair<string,int>> equipment;
public:
void virtual DealDamage(Entity*) const;
int GetHealth();
void virtual SetHealth(int);
int GetDefense();
void SetDefense(int);
};
class Player : Entity
{
private:
string armor,weapon,magic;
int mana,experience,healthPotions;
public:
bool CanCast(int);
void DealDamage(bool);
void SetEquipment(string);
void SetHealth(int,int);
int GetMana();
void SetMana(int);
};
class Enemy : Entity
{
public:

string DropLoot(int,bool);
int DropExperience(int,bool);
void GenerateSprite();
protected:
string Loot;

};
class Boss : Enemy
{
public:
void isInviincible(int);
private:
int TurnCounter;
bool invincibility;
string prefix;
};
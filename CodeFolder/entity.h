#include <string>
#include <utility>
#include <set>
using namespace std;
class Entity : Engine
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
set<pair<string,int>> equipment;
public:
void virtual DealDamage(Entity*);
int GetHealth();
void virtual SetHealth(int);
int GetDefense();
void SetDefense(pair<string,int> armor);
enum EquipType
{
    armor,weapon,spell
};
EquipType itemType;
};
class Player : Entity
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
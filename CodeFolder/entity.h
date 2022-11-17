#include <string>
using namespace std;
class Entity
{
public:
int Health;
int Attack;
string Defense;
int Level;
string AttackType;
protected:
void DealDamage(int);
void GetHealth();
void SetHealth(int);
void TakeDamage(int,int);
};
class Player : Entity
{
public:
string armor,weapon,magic;
int mana,experience,healthPotions;
private:
bool CanCast(int);
void DealDamage(bool);
void SetEquipment(string);
void GetMana();
void SetMana();
};
class Enemy : Entity
{
    public:
string loot;
string DropLoot(int);
int DropExperience(int);
void GenerateSprite();
};
class Boss : Enemy
{
public:
void isInviincible(int);
int takeDamage(bool,int,int);
private:
int TurnCounter;
bool invincibility;
string prefix;
};
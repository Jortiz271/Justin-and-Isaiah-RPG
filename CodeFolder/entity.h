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
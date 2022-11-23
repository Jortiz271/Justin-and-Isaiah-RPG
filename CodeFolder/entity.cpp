#include "entity.h"

void Entity::DealDamage(Entity* a) const
{
    if(Attack > a->GetDefense())
    {
    a->SetHealth(-Attack + a->GetDefense());
    }
}

int Entity::GetHealth()
{
return Health;
}
void Entity::SetHealth(int a)
{
if((Health + a) > 0)
{
    Health += a;
}
else
{
Dead = true;
}
}
int Entity::GetDefense()
{
return Defense;
}
void Entity::SetDefense(int a)
{
Defense = a;
}
bool Player::CanCast(int a)
{
return GetMana() >= 3 ? true : false;
}
void Player::DealDamage(bool a)
{
if(a)
{
    Player::Attack *= 3;
    Entity::DealDamage(this);
    Player::Attack /= 3;
}
else
{
Entity::DealDamage(this);
}
}
void Player::SetEquipment(string a)
{

}
void Player::SetHealth(int potAmnt,int healVal)
{

}
int Player::GetMana()
{
return mana;
}
void Player::SetMana(int a)
{
mana += a;
}


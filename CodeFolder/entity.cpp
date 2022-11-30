#include "entity.h"
#include "Handler.h"

int Entity::GetHealth()
{
return Health;
}
void Entity::SetHealth(int ChangeValue)
{
if((Health + ChangeValue) > 0)
{
    Health += ChangeValue;
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
void Entity::SetDefense(pair<string,int> armor)
{
Defense = armor.second;
}
bool Player::CanCast(int a)
{
return GetMana() >= 3 ? true : false;
}
void Player::DealDamage(Entity* enemy)
{
if(CanCast(mana))
{
    Attack *= spell.second;
    enemy->SetHealth(Attack - enemy->GetDefense());
    Attack /= spell.second;
    mana -= 3;
}
else
{
    if(Attack - enemy->GetDefense() > 0)
    {
        enemy->SetHealth(Attack - enemy->GetDefense());
    }
    else
    {
    }
}
}
void Player::SetEquipment(pair<string,int> thing,EquipType)
{

}
void Player::SetHealth(int potAmnt,int healVal)
{

}
int Player::GetMana()
{
return mana;
}
void Player::SetMana(int CurrFloor)
{
mana += CurrFloor;
}
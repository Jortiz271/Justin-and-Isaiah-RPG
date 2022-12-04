#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "entity.h"
using namespace std;
//inherits from entity with additonal behavior such as awarding exp loading a sprite and dealing its own damage
class BasicEnemy : public Entity
{

public:
	BasicEnemy();
	int dropExperience();
	sf::Sprite generateSprite();
	BasicEnemy(int,bool);
	int dealDamage(int CurrFloor);
private:
	sf::Sprite enemySprite;
};
#endif
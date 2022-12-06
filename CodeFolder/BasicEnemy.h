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
	sf::Sprite* getSprite();
	int dealDamage() override;
	int CurrFloor;
	void Deaded() override;
	sf::Sprite generateSprite();
	BasicEnemy(int CurrentFloor, bool Modifiable);
	sf::Sprite enemySprite;
	bool dead = false;
};
#endif
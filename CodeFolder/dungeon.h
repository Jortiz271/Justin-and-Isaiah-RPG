#pragma once
#include <vector>
#include "entity.h"
#include "BasicEnemy.h"
#include <SFML/Graphics.hpp>
using namespace std;
//Creates 1 of 4 different types of rooms ones with monster and a random rest room that regens health for player
//Spawn one Randmon Monster that you slash down as qucikly as possible
class Room
{
public:
    BasicEnemy* GenerateMonsters();
    sf::Sprite* RandomRoomBackground();
    bool isRestSite();
    void setRestSite(bool isIt);
    bool getRestSite();
    int awardhealth();
    Room();
    int getFloor();
private:
    sf::Sprite roomSprite;
    int MonsterNumber;
    int CurrFloor;
    bool restsite = false;
};

//Dungeon that Holds all the rooms and picks a random one
class Dungeon : public Room
{
private:
int FLOORMAX = 10;
int FloorMIN = 1;
vector<Room*> Rooms;
Room* CurrentRoom;

public:
void fillDungeonWithRooms();
void Advance();
void FinishDungeon();
void setFloor(int num);
};

#pragma once
#include <vector>
#include "entity.h"
#include "BasicEnemy.h"
#include <map>
using namespace std;
class Room
{
public:
int MonsterNumber;
int CurrFloor;
BasicEnemy GenerateMonster(int,bool);
vector<Entity*> GenerateRoomBattle();
bool Trap;
string TrapType;
vector<Entity*> Monsters;
Entity* CurrentMonster;
int WaitInRoom(int);
void PickBackground();
void SetCurrFloor();
};
class Dungeon
{
public:
int FLOORMAX = 10;
int FloorMIN = 1;

vector<Room*> Rooms;
Room* CurrentRoom;
enum FloorName
{
    Castle,Basement,Forest
};
std::map<FloorName, string> FloorToString;
void Advance();
void GenerateRooms();
void GenerateHouse();
void FinishDungeon();
int CurrFloor;
};

#include <vector>
#include "entity.h"
using namespace std;
class Room
{
public:
int MonsterNumber;
protected:
bool Trap;
string TrapType;
vector<Entity> Monsters;
Entity GenerateMonster(string,int,bool);
void AdvanceRoom(int);
int WaitInRoom(int);
void PickBackground();
bool SetTrap(int);
};
class MonsterHouse : Room
{
private:
int Waves;
bool IsComplete;
bool IsLastWave;
public:
vector<vector<Entity>> Wave;
vector<Entity> GenerateWave(int,bool);
void AdvanceRoom(bool,int);
};
class Dungeon
{
private:
int FLOORMAX;
int FloorMIN;
int CurrFloor;
vector<Room> Rooms;
enum FloorName
{
    Basement = 1,
    Forest = 2,
    Castle = 3

};
public:
int AdvanceFloor(int);
void GenerateRooms(int);
void GenerateHouse(int);
void FinishDungeon();
};

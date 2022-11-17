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
public:
int Waves;
bool IsComplete;
bool IsLastWave;
private:
vector<vector<Entity>> Wave;
vector<Entity> GenerateWave(int,bool);
void AdvanceRoom(bool,int);
};
class Dungeon
{
public:
int FLOORMAX;
int FloorMIN;
int CurrFloor;
vector<Room> Rooms;
enum FloorName
{
    Basement = 1,
    Forest = 2,
    Castle = 3,
    Prison = 4

};
protected:
int AdvanceFloor(int);
void GenerateRooms(int);
void FinishDungeon();
};

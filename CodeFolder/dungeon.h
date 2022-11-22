#include <vector>
#include "entity.h"
#include <map>
using namespace std;
class Room
{
public:
int MonsterNumber;
int RoomsSinceLastTrap;
Entity GenerateMonster(int,bool);
vector<Entity> GenerateRoomBattle();
void ResetRoom();
protected:
bool Trap;
string TrapType;
vector<Entity> Monsters;
Entity CurrentMonster;
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
int FLOORMAX = 10;
int FloorMIN = 1;
int CurrFloor;
vector<Room> Rooms;
Room CurrentRoom;
MonsterHouse BossRoom;
enum FloorName
{
    Castle,Basement,Forest
};
std::map<FloorName, string> FloorToString;
public:
int AdvanceFloor();
void GenerateRooms();
void GenerateHouse();
void FinishDungeon();
void PopulateFloorNameMap();
};

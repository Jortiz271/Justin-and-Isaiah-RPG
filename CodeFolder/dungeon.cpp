#include "dungeon.h"
Entity Room::GenerateMonster(int CurrFloor,bool modifiable)
{
    //Generate monster, then push it back into the vector of enemies/bosses.

}
void Room::AdvanceRoom(int RoomsRemaining)
{

}
int Room::WaitInRoom(int CurrentFloor)
{

}
void Room::PickBackground()
{

}
bool Room::SetTrap(int RoomsRemaining)
{

}
int Dungeon::AdvanceFloor()
{
    CurrFloor += 1;
}
void Dungeon::GenerateRooms()
{
    bool lastMonsterWasModified = false;
    //Generate a number of rooms equal to 3 more than the current floor.
    //Need to take the modulo of the current floors int value and pass it into our enumerator
    //so that we can get a string back and use that to select
    for(int i = 0; i < CurrFloor + 3; i++)
    {
        if(CurrFloor % 2 == 0 && i > 4 && !lastMonsterWasModified)
        {

            CurrentRoom.GenerateMonster(CurrFloor,true);
            lastMonsterWasModified = true;
        }
        else
        {
            CurrentRoom.GenerateMonster(CurrFloor,false);
            lastMonsterWasModified = false;
            
        }
        
    }

}
void Dungeon::GenerateHouse()
{

}
void Dungeon::FinishDungeon()
{
    if(CurrFloor = FLOORMAX)
    {
        //display win screen
    }
    
}
void Dungeon::PopulateFloorNameMap()
{
    FloorToString.emplace(Castle,"castle");
    FloorToString.emplace(Basement,"basement");
    FloorToString.emplace(Forest,"forest");
}
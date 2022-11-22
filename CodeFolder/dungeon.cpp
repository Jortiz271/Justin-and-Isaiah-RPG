#include "dungeon.h"
Entity Room::GenerateMonster(int CurrFloor,bool modifiable)
{
    //Generate monster, then push it back into the vector of enemies/bosses.

}
void Room::AdvanceRoom(int RoomsRemaining)
{
    //check if there are any more rooms after this one.
    if (RoomsRemaining > 0)
    {

    }
    //if there are no more rooms after this one, call advance floor
    //make sure to pop rooms as you pass through them to save space.

}
int Room::WaitInRoom(int CurrentFloor)
{
    //give back health to the player(more health regained in lower floors)

}
void Room::PickBackground()
{
    //setup the backgound texture for the floor

}
bool Room::SetTrap(int RoomsRemaining)
{
    //set a trap in a room, have it trigger when the player enters

}
vector<Entity> Room::GenerateRoomBattle()
{
    bool lastMonsterWasModified = false;
    //Generate a number of monsters equal to 3 more than the current floor
    for (int i = 0; i < CurrFloor + 3; i++)
    {
        if (i > 4 && !lastMonsterWasModified)
        {

            CurrentMonster = CurrentRoom.GenerateMonster(CurrFloor, true);
            lastMonsterWasModified = true;
            Monsters.push_back(CurrentMonster);
        }
        else
        {
            CurrentMonster = CurrentRoom.GenerateMonster(CurrFloor, false);
            lastMonsterWasModified = false;
            Monsters.push_back(CurrentMonster);

        }

    }

}
int Dungeon::AdvanceFloor()
{
    //clear the vector of rooms for redundancy, then increment the number of current floor, if its less tha FloorMax, else call finish dungeon.
    if (CurrFloor + 1 < FloorMax)
    {
        CurrFloor += 1;
    }
    else
    {
        FinishDungeon();
    }
    }
void Dungeon::GenerateRooms()
{
    for (int i = 0; i < CurrFloor + 2; i++)
    {
        CurrentRoom.GenerateRoomBattle();
        Rooms.push_back(CurrentRoom);
        CurrentRoom.ResetRoom();
    }
    BossRoom.GenerateHouse();
    Rooms.push_back(BossRoom);
   
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
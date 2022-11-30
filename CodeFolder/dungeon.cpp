#include "dungeon.h"
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
vector<Entity*> Room::GenerateRoomBattle()
{
    bool lastMonsterWasModified = false;
    //Generate a number of monsters equal to 3 more than the current floor
    for (int i = 0; i < CurrFloor + 3; i++)
    {
        if (i > 4 && !lastMonsterWasModified)
        {

            CurrentMonster = new BasicEnemy(CurrFloor, true);
            lastMonsterWasModified = true;
            Monsters.push_back(CurrentMonster);
        }
        else
        {
            CurrentMonster = new BasicEnemy(CurrFloor, false);
            lastMonsterWasModified = false;
            Monsters.push_back(CurrentMonster);

        }

    }

}
int Dungeon::AdvanceFloor()
{
    //clear the vector of rooms for redundancy, then increment the number of current floor, if its less tha FloorMax, else call finish dungeon.
    if (CurrFloor + 1 < FLOORMAX)
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
    }
   
}
void Dungeon::FinishDungeon()
{
    if(CurrFloor == FLOORMAX)
    {
        //display win screen
    }
    
}

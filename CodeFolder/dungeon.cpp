#include "dungeon.h"
#include "BasicEnemy.h"
#include "TextureHolder.h"
using namespace sf;
//Constructor makes a room, checks if its a rest site if it is no monster spawn will occur and give player health
//if the room isnt a constructor, it generates a pointer to a monster object and pushes it into the room's monster storage
Room::Room()
{
    Room::RandomRoomBackground();
    srand(time(0));
    int randomroom = (rand() % 5) + 1;
    if (randomroom == 5)
    {
        this->restsite = true;
    }
    else
    {
        Room::GenerateMonsters();
    }
}
//deletes the room
void Room::DestroyRoom()
{
    delete this;
}
int Room::getFloor()
{
    return this->CurrFloor;
}
void Room::setRestSite(bool isIt)
{
    this->restsite = isIt;

}

bool Room::getRestSite()
{
    return restsite;
}

bool Room::isRestSite()
{
    return true;
}
//returns a pointer to a new enemy
BasicEnemy Room::GenerateMonsters()
{
    BasicEnemy Enemy;
    return Enemy;
}

//returns a pointer to 1 of 3 random rooms
sf::Sprite Room::RandomRoomBackground()
{
    roomSprite.setOrigin(0, 0);
    srand(time(0));
    int randomSelection = (rand() % 3) + 1;
    if (randomSelection == 1)
    {
        
        roomSprite = Sprite(TextureHolder::GetTexture("graphics/dungeon1.jpg"));
        return roomSprite;
    }
    else if (randomSelection == 2)
    {
        roomSprite = Sprite(TextureHolder::GetTexture("graphics/dungeon2.jpg"));
        return roomSprite;
    }
    else
    {
        roomSprite = Sprite(TextureHolder::GetTexture("graphics/dungeon3.jpg"));
        return roomSprite;
    }
}
//sets the current floor
void Dungeon::setFloor(int num)
{
    CurrFloor = num;
}
//clear the vector of rooms for redundancy, then increment the number of current floor, if its less than FloorMax, else call finish dungeon.
void Dungeon::Advance()
{
    if (Room::getFloor() + 1 < FLOORMAX)
    {
        setFloor(Room::getFloor() + 1);
        for (int i = 0; i < 10; i++)
        {
            Rooms.at(i);
        }
        Rooms.clear();
        fillDungeonWithRooms();
        EnemyNum = 0;
        std::cout << "you advanced to Floor: " + Room::getFloor() << std::endl;
    }
    else
    {
        FinishDungeon();
    }
}

//adds rooms into dungeon until dungeon is full of 10 rooms
void Dungeon::fillDungeonWithRooms()
{
    for (int i = 0; i < 10; i++)
    {
        Room* newRoom = new Room;
        Rooms.push_back(newRoom);
    }
    RoomNum = 0;
}

void Dungeon::FinishDungeon()
{
    if (getFloor() == FLOORMAX)
    {
        std::cout << "you win!" << std::endl;
        finished = true;
    }
}
//checks if  the enemy is dead, and if the room the player is in is less than 10
//if it is, moves the current room forward by one, and increments the RoomsNumber
//if the vector is at its end, calls advance to move to the next floor
void Dungeon::AdvanceRoom()
{
    if (CurrentEnemy->Dead() && RoomNum < 9)
    {
        RoomNum++;
        CurrentRoom = Rooms.at(RoomNum);
        if (!CurrentRoom->getRestSite())
        {
            CurrentEnemy = CurrentRoom->Enemies.at(RoomNum);
        }
        else
        {
            std::cout << "Rest Room logic not implemented yet" << std::endl;
        }
    }
    else
    {
        std::cout << "Called Advance Floor" << std::endl;
        Advance();
    }
}
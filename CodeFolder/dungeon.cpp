#include "dungeon.h"
#include "BasicEnemy.h"
using namespace sf;
//Constructor makes a room, checks if its a rest site if it is no monster spawn will occur and give player health
//if the room isnt a constructor, it generates a pointer to a monster object and pushes it into the room's monster storage
Room::Room()
{
    CurrFloor = 10;
    Room::RandomRoomBackground();
    srand(time(0));
    int randomroom = (rand() % 5) + 1;
    if (randomroom == 5)
    {
        this->restsite = true;
    }
    else    
    {
        Enemies.push_back(GenerateMonsters());
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
BasicEnemy* Room::GenerateMonsters()
{
    BasicEnemy* Enemy = new BasicEnemy;
    return Enemy;
}

//returns a pointer to 1 of 3 random rooms
sf::Sprite* Room::RandomRoomBackground()
{
    Texture Room1, Room2, Room3;
    Room1.loadFromFile("graphics/dungeon1.jpg");
    Room2.loadFromFile("graphics/dungeon2.jpg");
    Room3.loadFromFile("graphics/dungeon3.png");

    Sprite* dungeonRoom1 = new Sprite;
    Sprite* dungeonRoom2 = new Sprite;
    Sprite* dungeonRoom3 = new Sprite;

    dungeonRoom1->setTexture(Room1);
    dungeonRoom2->setTexture(Room2);
    dungeonRoom3->setTexture(Room3);

    srand(time(0));
    int randomSelection = (rand() % 3) + 1;
    if (randomSelection == 1)
    {
        return dungeonRoom1;
    }
    else if (randomSelection == 2)
    {
        return dungeonRoom2;
    }
    else
    {
        return dungeonRoom3;
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
         for(int i = 0; i < 10; i++)
         {
            Rooms.at(i)->DestroyRoom();
         }
         Rooms.clear();
         fillDungeonWithRooms();
         EnemyNum = 0;
         RoomNum = 0;
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
        std::cout << "Room Address for Room number " << i << ": " << newRoom << std::endl;
    }
    RoomNum = 0;
    EnemyNum = 0;
    CurrentEnemy = Rooms.at(RoomNum)->Enemies.at(0);
    std::cout << "Address for CurrentEnemy " << CurrentEnemy << std::endl;
    CurrentRoom = Rooms.at(RoomNum);
    finished = false;
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
    if(CurrentEnemy->Dead && RoomNum < 9)
    {
        RoomNum++;
        std::cout << "Current RoomNum: " <<RoomNum << std::endl;
        CurrentRoom = Rooms.at(RoomNum);
        std::cout << CurrentRoom << std::endl;
        if(!CurrentRoom->getRestSite())
        {
        CurrentEnemy = CurrentRoom->Enemies.at(0);
        }
        else
        {
            HealthToAward = CurrentRoom->awardhealth();
        }
    }
    else
    {
        Advance();
    }
}
int Room::awardhealth()
{
    return CurrFloor * 2;
}
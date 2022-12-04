#include "dungeon.h"
#include "BasicEnemy.h"
using namespace sf;
//Constructor makes a room, checks if its a rest site if it is no monster spawn will occur and give player health
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
    BasicEnemy *Enemy = new BasicEnemy;
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

//clear the vector of rooms for redundancy, then increment the number of current floor, if its less tha FloorMax, else call finish dungeon.
void Dungeon::Advance()
{
    if (Room::getFloor() + 1 < FLOORMAX)
    {
         setFloor(Room::getFloor() + 1);
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
        Room *newRoom = new Room;
        Rooms.push_back(newRoom);
    }
}

void Dungeon::FinishDungeon()
{
    if(getFloor() == FLOORMAX)
    {
        //display win screen
    }   
}


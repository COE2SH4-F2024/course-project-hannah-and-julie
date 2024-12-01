#include "Food.h"
#include "GameMechs.h"
#include "Player.h"
#include <iostream>
#include "MacUILib.h"

using namespace std;

Food::Food()
{
    foodPos.setObjPos(-1,-1,'o');
    //initialize outside of game board

}

//deconstructor
Food::~Food()
{

    //nothing to free
}


void Food::generateFood(GameMechs* thisGMRef, objPos blockOff)
{
    int i, randomx, randomy;
    int overlap = 1;
    myGameRef = thisGMRef;


 
    srand(time(NULL));

    while (overlap == 1)
    {
        if(myGameRef == nullptr) //just a safety check to ensure gamRef is not empty
        {
            break;
        }
        randomx = (rand() % (myGameRef->getBoardSizeX() - 2)) + 1; //random x coordinate
        randomy = (rand() % (myGameRef->getBoardSizeY() - 2)) + 1; //random y coordinate

        //ensures food does not generate at same coordinates as the player
        if(randomx != blockOff.pos->x && randomy != blockOff.pos->y) //objPos blockOff is just player instance
        {
            foodPos.setObjPos(randomx,randomy,'o');  
            overlap = 0;
        }
 
    }


}

objPos Food::GetFoodPos() const
{
    //returns food 
    return foodPos;
}


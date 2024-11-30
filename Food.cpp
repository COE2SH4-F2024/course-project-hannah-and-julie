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


void Food::generateFood(GameMechs* thisGMRef, objPos blockOff) //objPos blockOff
{
    int i, randomx, randomy;
    int overlap = 1;
    myGameRef = thisGMRef;


 
    srand(time(NULL));

    while (overlap == 1)
    {
        if(myGameRef == nullptr)// || blockOff.pos == nullptr)
        {
            break;
        }
        randomx = (rand() % (myGameRef->getBoardSizeX() - 2)) + 1;
        randomy = (rand() % (myGameRef->getBoardSizeY() - 2)) + 1;


        if(randomx != blockOff.pos->x && randomy != blockOff.pos->y)
        {
            foodPos.setObjPos(randomx,randomy,'o');  
            overlap = 0;
        }
 
    }


}

objPos Food::GetFoodPos() const
{
    return foodPos;
}


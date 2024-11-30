#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"

#include <cstdlib>
#include <time.h>

using namespace std;

class Food
{

    private:
        objPos foodPos;
        //Instance of objPos where food has some x cor, y cor and character ' '
        GameMechs* myGameRef;
        Player *myPlayer; //Maybe use to get access to player instance coordinates and check to ensure food generation does not overlap with player pos. 
        objPos blockOff;
        
    public:
        Food();
        ~Food();
        void generateFood(GameMechs* thisGMRef, objPos blockOff); //, objPos blockOff
        objPos GetFoodPos() const;
            

};

#endif
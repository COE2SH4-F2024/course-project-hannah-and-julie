// #include "Food.h"
// #include "GameMechs.h"
// #include "Player.h"
// #include <iostream>
// #include "MacUILib.h"

// using namespace std;

// Food::Food()
// {
//     foodPos.setObjPos(-1,-1,'o');
//     //initialize outside of game board

// }

// //deconstructor
// Food::~Food()
// {

//     //nothing to free
// }


// void generateFood(GameMechs* thisGMRef, objPosArrayList* blockOff)
// {
//     int i, randomx, randomy;
//     int overlap = 1;
//     GameMechs* myGameRef = thisGMRef;


 
//     srand(time(NULL));

//     while (overlap == 1)
//     {
//         if(myGameRef == nullptr) //just a safety check to ensure gamRef is not empty
//         {
//             break;
//         }
//         randomx = (rand() % (myGameRef->getBoardSizeX() - 2)) + 1; //random x coordinate
//         randomy = (rand() % (myGameRef->getBoardSizeY() - 2)) + 1; //random y coordinate

//         //ensures food does not generate at same coordinates as the player
//         if(randomx != blockOff.pos->x && randomy != blockOff.pos->y) //objPos blockOff is just player instance
//         {
//             foodPos.setObjPos(randomx,randomy,'o');  
//             overlap = 0;
//         }
 
//     }


// }

// objPos Food::GetFoodPos() const
// {
//     //returns food 
//     return foodPos;
// }
#include "Food.h"
#include "GameMechs.h"
#include "Player.h"
#include <iostream>
#include "MacUILib.h"

using namespace std;

// Constructor
Food::Food()
{
    foodPos.setObjPos(-1, -1, 'o'); // Initialize food position outside the game board
}

// Destructor
Food::~Food()
{
    // Nothing to free
}

// Function to generate food at a random location, avoiding player positions
void Food::generateFood(GameMechs* thisGMRef, objPosArrayList* blockOff)
{
    int randomx, randomy;
    bool overlap = true; // Flag to indicate overlap

    GameMechs* myGameRef = thisGMRef;
    srand(time(NULL));

    while (overlap)
    {
        if (myGameRef == nullptr) // Safety check to ensure game reference is valid
        {
            break;
        }

        randomx = (rand() % (myGameRef->getBoardSizeX() - 2)) + 1; // Random x coordinate
        randomy = (rand() % (myGameRef->getBoardSizeY() - 2)) + 1; // Random y coordinate

        overlap = false; // Assume no overlap

        // Iterate through the player's position list to check for overlap
        for (int i = 0; i < blockOff->getSize(); i++)
        {
            objPos playerSegment = blockOff->getElement(i);
            if (randomx == playerSegment.pos->x && randomy == playerSegment.pos->y)
            {
                overlap = true; // Overlap found
                break;
            }
        }

        // If no overlap, set the food position
        if (!overlap)
        {
            foodPos.setObjPos(randomx, randomy, 'o');
        }
    }
}

// Function to get the current food position
objPos Food::GetFoodPos() const
{
    return foodPos; // Return the food position
}

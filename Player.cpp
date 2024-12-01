#include "Player.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include "Food.h"
#include "objPosArrayList.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();
    //creates objPos instance of headPos which gives position of head element in list
    // objPos headPos(thisGMRef->getBoardSizeX()/2, thisGMRef->getBoardSizeY()/2, '*');
    // playerPosList->insertHead(headPos);

    // // //ititializes headPos at middle of board 
    playerPosList->insertHead(objPos(10, 5, '*')); // Starting Position DONT DELETE
    playerPosList->insertHead(objPos(9, 5, '*')); //Can delete when implementing growing snake feature
    playerPosList->insertHead(objPos(8, 5, '*')); 
    playerPosList->insertHead(objPos(7, 5, '*')); //I just have these here to make sure snake can move with 
    playerPosList->insertHead(objPos(6, 5, '*')); //a body length of more than 1




    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here

    delete playerPosList;

    //Only use delete where you use new 

}

objPos Player::getPlayerPos() const
{
    //returns reference to the playerPos array list
    return playerPosList->getHeadElement();
}

objPosArrayList *Player::getPlayerPosList() const
{
    // returns reference to player objPos array list
    return playerPosList;
 
}

// More methods to be added

void Player::updatePlayerDir() {
    // Get the latest input from the GameMechs object
    char input = mainGameMechsRef->getInput();
    MacUILib_printf("%c", input);

    // Update direction state based on input
    switch (input) {
        case 'w': // Move up
            if (myDir != DOWN && myDir != UP) // Prevent reversing direction
                myDir = UP;
            break;
        case 's': // Move down
            if (myDir != UP && myDir != DOWN) // Prevent reversing direction
                myDir = DOWN;
            break;
        case 'a': // Move left
            if (myDir != RIGHT && myDir != LEFT) // Prevent reversing direction
                myDir = LEFT;
            break;
        case 'd': // Move right
            if (myDir != LEFT && myDir != RIGHT) // Prevent reversing direction
                myDir = RIGHT;
            break;
        default:
            break; // Ignore invalid input
    }

    // Clear the input buffer in GameMechs
    //GameMechs::clearInput();
}


void Player::movePlayer() {



    //ITERATION 3 PSEUDO CODE

   
    objPos currentHead = playerPosList->getHeadElement(); // Get current head position
    objPos newHead = currentHead;  // Create a new position object based on current position

    if(myDir == STOP)
    {
        return;
    }
    // Update the position based on the current direction
    switch (myDir) 
    {

    //WRAP AROUND LOGIC

        case UP:
            playerPos.pos->y -= 1;
            if (playerPos.pos->y < 1) // Wrap around if moving out of bounds
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
            break;
        case DOWN:
        //sets new head pos to the current head pos +1
        //same as saying newHead.pos->y++
            newHead.pos->y = (currentHead.pos->y + 1);
            if (newHead.pos->y >= mainGameMechsRef->getBoardSizeY()-1) // Wrap to top boundary
            {
                newHead.pos->y = 1;
            }
            break;
        case LEFT:
            playerPos.pos->x -= 1;
            if (playerPos.pos->x < 1) // Wrap around
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            break;
        case RIGHT:
        //sets new head pos to the current head pos +1
        //same as saying newHead.pos->x++
            newHead.pos->x = (currentHead.pos->x + 1);
            if (newHead.pos->x >= mainGameMechsRef->getBoardSizeX()-1) // Wrap to right boundary
            {
                newHead.pos->x = 1;
            }
            break;
        // case STOP:
        default:
            // No movement for STOP or invalid state
            break;
    }
    //inserts newHead to head of list for regular movement 
    playerPosList->insertHead(newHead);

    // remove tail
    playerPosList->removeTail();

    //(later) For feature 2, check if new temp objPos
    //overlaps from foodPos (get it from Food class)
    //to check for overlap, use isPosEqual 
    //If there is overlap , comsume food and increase score

    //feature 3, if no overlap, remove tail and complete movement
    

}

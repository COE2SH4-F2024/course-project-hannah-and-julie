#include "player.h"
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
        playerPos=objPos();
    //mainGameMechsRef=thisGMRef;
    objPos playerPos(10,5,'*');

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    free(mainGameMechsRef);
}

objPos Player::getPlayerPos() const
{
    // Get the current position pointer
    return playerPos;
 
}

// More methods to be added
// Player::Player(GameMechs* thisGMRef)
// {
//     playerPos=objPos();
//     //mainGameMechsRef=thisGMRef;
//     mainGameMechsRef=gmRef;
//     myDir=STOP;
//     objPos playerPos(10,5,'*');
// }

void Player::updatePlayerDir() {
    // Get the latest input from the GameMechs object
    char input = mainGameMechsRef->getInput();

    // Update direction state based on input
    switch (input) {
        case 'w': // Move up
            if (myDir != DOWN) // Prevent reversing direction
                myDir = UP;
            break;
        case 's': // Move down
            if (myDir != UP) // Prevent reversing direction
                myDir = DOWN;
            break;
        case 'a': // Move left
            if (myDir != RIGHT) // Prevent reversing direction
                myDir = LEFT;
            break;
        case 'd': // Move right
            if (myDir != LEFT) // Prevent reversing direction
                myDir = RIGHT;
            break;
        default:
            break; // Ignore invalid input
    }

    // Clear the input buffer in GameMechs
    //GameMechs::clearInput();
}


void Player::movePlayer() {
    

    // Update the position based on the current direction
    objPos currentPos=getPlayerPos(); 
    switch (myDir) {
        case UP:
            currentPos.pos->y -= 1;
            if (currentPos.pos->y < 0) // Wrap around if moving out of bounds
                currentPos.pos->y = mainGameMechsRef->getBoardSizeY() - 1;
            break;
        case DOWN:
            currentPos.pos->y += 1;
            if (currentPos.pos->y >= mainGameMechsRef->getBoardSizeY()) // Wrap around
                currentPos.pos->y = 0;
            break;
        case LEFT:
            currentPos.pos->x -= 1;
            if (currentPos.pos->x < 0) // Wrap around
                currentPos.pos->x = mainGameMechsRef->getBoardSizeX() - 1;
            break;
        case RIGHT:
            currentPos.pos->x += 1;
            if (currentPos.pos->x >= mainGameMechsRef->getBoardSizeX()) // Wrap around
                currentPos.pos->x = 0;
            break;
        case STOP:
        default:
            // No movement for STOP or invalid state
            break;
    }
}

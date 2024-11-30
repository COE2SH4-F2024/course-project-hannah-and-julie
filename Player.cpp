#include "Player.h"
#include "GameMechs.h"
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    // playerPos=objPos();
    // mainGameMechsRef=thisGMRef;
    // objPos playerPos(10,5,'*');
    playerPos.pos->x=mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y=mainGameMechsRef->getBoardSizeY()/2;
    playerPos.pos->x=5;
    playerPos.pos->y=5;
    playerPos.symbol='*';



    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    //delete(mainGameMechsRef);

    //Only use delete where you use new 

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
    switch (myDir) {
        case UP:
            playerPos.pos->y -= 1;
            if (playerPos.pos->y < 1) // Wrap around if moving out of bounds
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 1;
            break;
        case DOWN:
            playerPos.pos->y += 1;
            if (playerPos.pos->y >= mainGameMechsRef->getBoardSizeY()-1) // Wrap around
                playerPos.pos->y = 1;
            break;
        case LEFT:
            playerPos.pos->x -= 1;
            if (playerPos.pos->x < 1) // Wrap around
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 1;
            break;
        case RIGHT:
            playerPos.pos->x += 1;
            if (playerPos.pos->x >= mainGameMechsRef->getBoardSizeX()-1) // Wrap around
                playerPos.pos->x = 1;
            break;
        case STOP:
        default:
            // No movement for STOP or invalid state
            break;
    }
}

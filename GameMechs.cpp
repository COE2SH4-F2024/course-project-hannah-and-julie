#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0; //holds most recent input collected via MacULib_getChar()
    exitFlag = false;
    loseFlag = false; //boolean recording whether player has lost or won, is used to determine the display message at end of game
    score = 0; //holds current score of player

    boardSizeX = 30; //Board size in X
    boardSizeY = 15; //Board size in Y

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0; //holds most recent input collected via MacULib_getChar()
    exitFlag = false;
    loseFlag = false; //boolean recording whether player has lost or won, is used to determine the display message at end of game
    score = 0; //holds current score of player

    boardSizeX = boardX; //Board size in X
    boardSizeY = boardY; //Board size in Y
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //do not need to free anything CURRENTLY
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() 
{
    if (MacUILib_hasChar() != 0)
    {
        input = MacUILib_getChar();
    }

    return input;

}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    //Condition for exit flag
    exitFlag = true;

}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here

//FOOD METHODS to be added here
// will do in iteration 2B
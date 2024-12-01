#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    private:
        char input; //holds most recent input collected via MacULib_getChar()
        bool exitFlag;
        bool loseFlag; //boolean recording whether player has lost or won, is used to determine the display message at end of game
        int score; //holds current score of player

        int boardSizeX; //Board size in X
        int boardSizeY; //Board size in Y

        objPos food; 

    public:
        GameMechs(); 
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not?
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput() const;
        
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();
        
        // More methods should be added here
        void collectAsynchInput();
};

#endif
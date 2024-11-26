#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *myGM; //Pointer to Game Mechanics Class

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    myGM = new GameMechs(); //Initialized on the heap, must delete/deallocate .
}

void GetInput(void)
{
    char input;
    int MacUILib_hasChar(void);
    // if MacULib_hasChar detects a character typed in keyboard, MacUILib_hasChar will become 1 or any non-zero number
    // if MacUILib_hasChar does not detect a typed character in keyboard, it remains as 0. we must always check first if a character was detected in keyboard before using MacUILib_getChar to grab said character.
    if (MacUILib_hasChar() != 0)
    {
        myGM->setInput(MacUILib_getChar());
        
        //NOTE to access input, use myGM->getInput(); 
        //input = myGM->getInput();
    }
    
    
}

void RunLogic(void)
{
    char input = myGM->getInput();
    if(input != 0)
    {
        switch(input)
        {
            //Exit flag is set to space bar right now
            //Can change later
            case ' ':
                myGM->setExitTrue();
                break;

            //also can change the increment score case
            //INCREMENT SCORE
            case '+':
            case '=':
                myGM->incrementScore();
                break;

            //LOSE GAME
            case 'l':
            case 'L':
                myGM->setLoseFlag();
                //myGM->setExitTrue();
                //not sure if losing is suppose to automatically shut down game or if player must shut down automatically
                break;
        }
    }

    myGM->clearInput();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    int row, col;
    //row is board height 
    for( row = 0; row <= myGM->getBoardSizeY() -1 ; row++)
    {
        //col is board width
        for( col = 0; col <= myGM->getBoardSizeX() -1; col++)
        {
            if(row == 0 || col == 0 || col == myGM->getBoardSizeX() - 1 || row == myGM->getBoardSizeY() -1)
            {
                MacUILib_printf("#");
            }
            //This is directly pasted from my PPA, it just needs the correct player object to be implemented

            // else if (row == player.y && col == player.x)
            // {
            //     MacUILib_printf("%c", player.symbol);
            // }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    //FOR DEBUGGING, CAN DELETE LATER
    // int score = myGM->getScore();
    // MacUILib_printf("score = %d", score);

    //LOST GAME MESSAGE
    bool loser = myGM->getLoseFlagStatus();
    if(loser)
    {
        MacUILib_printf("You Lost !!");
        //myGM->setExitTrue();
        //not sure if losing is suppose to automatically shut down game or if player must shut down automatically
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();

    //DEALLOCATIONS
    delete(myGM);
}

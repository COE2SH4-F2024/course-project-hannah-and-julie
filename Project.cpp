#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"
#include "Food.h"
using namespace std;

#define DELAY_CONST 100000

GameMechs *myGM; //Pointer to Game Mechanics Class
Player *myPlayer; //Pointer to Player class
Food *myFood; //pointer to food class

//objPos playerPos=myPlayer->getPlayerPos();
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
    // makes it a second instance and makes myplayer and mygm talk
    myPlayer= new Player(myGM);
    myFood = new Food();


   myFood->generateFood(myGM, myPlayer->getPlayerPos()); //initializes instance of food 

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
    myPlayer->updatePlayerDir();

        // Move the player based on updated direction
        myPlayer->movePlayer();
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
    objPos playerPos=myPlayer->getPlayerPos();
    objPos foodPos = myFood->GetFoodPos();

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();
    //col is board height -----> pos in the y!!!!
    for( col = 0; col < boardY; col++)
    {
        //row is board width -----> pos in the x!!!!
        for( row = 0; row < boardX; row++) //can change myGM->getBoardSizeX(); to boardY
        {
            
            //This is directly pasted from my PPA, it just needs the correct player object to be implemented
            if(row == 0 || col == 0 || col == boardY - 1 || row == boardX -1)
            {
                MacUILib_printf("#");
            }
            else if(row == playerPos.pos->x && col == playerPos.pos->y)
            {
                MacUILib_printf("%c",playerPos.symbol);
            }
            else if(row == foodPos.pos->x && col == foodPos.pos->y) //food doesnt show up when foodPos.pos is not within the range of boardY and boardX
            {
                MacUILib_printf("%c",foodPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
    
        }
          MacUILib_printf("\n");

    }
    //printing coordinates of food to debug
    //DELETE LATER!!!
    MacUILib_printf("foodPos x = %d ", foodPos.getObjPos().pos->x);

    MacUILib_printf("foodPos y = %d", foodPos.getObjPos().pos->y);



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
    delete(myPlayer);
    //delete(myFood);
}








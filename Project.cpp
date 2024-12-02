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

bool ate=false;
bool collide= false;
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
    

   myFood->generateFood(myGM, myPlayer->getPlayerPosList()); //initializes instance of food 

}

void GetInput(void)
{
    char input;
    int MacUILib_hasChar(void);
    //if MacULib_hasChar detects a character typed in keyboard, MacUILib_hasChar will become 1 or any non-zero number
    //if MacUILib_hasChar does not detect a typed character in keyboard, it remains as 0. we must always check first if a character was detected in keyboard before using MacUILib_getChar to grab said character.
    if (MacUILib_hasChar() != 0)
    {
        myGM->setInput(MacUILib_getChar());
        
        //NOTE to access input, use myGM->getInput(); 
        input = myGM->getInput();
    }

//idk if we need this cuz the function above is doing exactly this part does
//Maybe uncomment the line below idk yet 
// myGM -> collectAsynchInput();
    
    
}

void RunLogic(void)
{
    char input = myGM->getInput();
    myPlayer->updatePlayerDir(); 

        // Move the player based on updated direction
    myPlayer->movePlayer();
    collide=myPlayer->checkSelfCollision();

    if(collide) //if snake collides with itself
    {
        myGM->setLoseFlag();
        //MacUILib_printf("Collision detected! Game over.\n");
        //myGM->setExitTrue(); 
    }
    if (myPlayer->checkFoodConsumption(myFood->GetFoodPos()))
    {
        ate = true;
        myPlayer->increasePlayerLength();
        myFood->generateFood(myGM, myPlayer->getPlayerPosList());
        ate = false; // Reset after regenerating food
    }
    
    
    if(input != 0)
    {
        
        switch(input)
        {
            //Exit flag is set to space bar right now
            //Can change later
            case ' ':
                myGM->setExitTrue();
                break;

            //LOSE GAME
            case 'l':
            case 'L':
                myGM->setLoseFlag();
                //not sure if losing is suppose to automatically shut down game or if player must shut down automatically
                break;
            //if you press f, food is regenerated at a new position
            case 'f':
            case 'F':

                myFood->generateFood(myGM, myPlayer->getPlayerPosList());
                break;
            
        }
        
        
    }
    
    myGM->clearInput();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    
    int row, col;

    //objPosArrayList* playerPos = myPlayer->getPlayerPosList();
    objPosArrayList* playerPos = myPlayer->getPlayerPosList();
    int playerSize = playerPos->getSize();

    objPos foodPos = myFood->GetFoodPos();

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();


    //col is board height -----> pos in the y!!!!
    for( col = 0; col < boardY; col++)
    {
        //row is board width -----> pos in the x!!!!
        for( row = 0; row < boardX; row++) //can change myGM->getBoardSizeX(); to boardY
        {
            bool isSnake = false;
                //bool isFood = false;

            for(int k = 0; k < playerSize; k++)
            {
                objPos bodyPart = playerPos->getElement(k);

                //iteration3: check if the current segment x,y pos matches the i,j coordinate
                //if yes, print the element on the screen
                if (row == bodyPart.pos->x && col == bodyPart.pos->y)
                {
                    // MacUILib_printf("%d", bodyPart.pos->x);
                    // MacUILib_printf("%d", bodyPart.pos->x);
                    MacUILib_printf("%c", bodyPart.symbol);
                    isSnake = true;
                    break;
                }

                //We need to skip the if-else block below 
                //maybe use continue or a flag
            }
            //at the end of for loop, do something to determine whether to continue with if-else 


            
            if(!isSnake)
            {
                //checks if border
                if(row == 0 || col == 0 || col == boardY - 1 || row == boardX -1)
                {
                    MacUILib_printf("#");
                }
                //otherwise print blank space

                else if(row == foodPos.pos->x && col == foodPos.pos->y) //food doesnt show up when foodPos.pos is not within the range of boardY and boardX
                {
                    MacUILib_printf("%c",foodPos.symbol);
                }
                else
                {
                    MacUILib_printf(" ");
                }

            }
    
        }
          MacUILib_printf("\n");

    }

    //printing coordinates of food to debug
    //DELETE LATER!!!

    // MacUILib_printf("foodPos x = %d ", foodPos.getObjPos().pos->x);

    // MacUILib_printf("foodPos y = %d", foodPos.getObjPos().pos->y);


    if(myGM->getExitFlagStatus())
    {
        MacUILib_printf("GAME EXITED \n");
        MacUILib_printf("Your final score is: %d", myPlayer->getPlayerPosList()->getSize()-1);
        MacUILib_Delay(1000000);//Delays so player can read score
        MacUILib_Delay(1000000);
        MacUILib_Delay(1000000);
        MacUILib_Delay(1000000);

    }

    if(myGM->getLoseFlagStatus())
    {
        
        MacUILib_printf("You Lost !! \n");
        MacUILib_printf("Your final score is: %d \n", myPlayer->getPlayerPosList()->getSize()-1);
        MacUILib_printf("Game will shut down automatically in a few seconds.\n");
        MacUILib_Delay(1000000);//Delays so player can read score
        MacUILib_Delay(1000000);
        MacUILib_Delay(1000000);
        MacUILib_Delay(1000000);
        //then automatically shuts down
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
    delete(myFood);
}

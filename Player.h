#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Food;

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum DIR {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state
        //objPos playerPos;
        Player(GameMechs* thisGMRef);
        ~Player();

        //objPos getPlayerPos() const; // Upgrade this in iteration 3.      
        objPosArrayList* getPlayerPosList() const; 
        void updatePlayerDir();
        void movePlayer();
        objPos getPlayerPos() const;
        
        // More methods to be added here
        objPos playerPos; 
    private:
        //objPos playerPos; // Upgrade this in iteration 3.  

        objPosArrayList* playerPosList;
        
        
        enum DIR myDir;

        // Need a reference to the Main Game Mechanisms
        //GameMechs* mainGameMechsRef;
        
        Food* myFood;
        //objPos getPlayerPos() const;
        GameMechs* mainGameMechsRef;
        //objPos getPlayerPos() const;
};

#endif
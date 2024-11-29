#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum DIR {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        objPos getPlayerPos() const; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        void movePlayer();
        
        // More methods to be added here

    private:
        objPos playerPos; // Upgrade this in iteration 3.  
        //playerPos.pos = new Position;     
        enum DIR myDir;

        // Need a reference to the Main Game Mechanisms
        //GameMechs* mainGameMechsRef;
        

        //objPos getPlayerPos() const;
        GameMechs* mainGameMechsRef;
        //objPos getPlayerPos() const;
};

#endif
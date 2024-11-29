
#ifndef OBJPOS_H
#define OBJPOS_H

// #include "GameMechs.h"  // Commented

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

enum DIR
{
    DOWN,
    UP,
    LEFT,
    RIGHT,
}; 

class objPos
{
    public:
        Pos* pos;        
        char symbol;

        objPos();
        objPos(int xPos, int yPos, char sym);
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        ~objPos();
        objPos& operator=(const objPos& other);
        objPos(const objPos& other);
        
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
        
        
        DIR myDIR=UP;
        //track players pos
        DIR currentDIR;
        
    private:
        //iteration 1A
        void playerPos() const;
        DIR myDir() const;
        // GameMechs* mainGameMechsRef;  // Commented
    



};
#endif
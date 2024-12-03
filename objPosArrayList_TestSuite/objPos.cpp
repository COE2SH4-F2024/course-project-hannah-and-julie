
#include "objPosArrayList.h"
#include "objPos.h"

objPos::objPos() //default constructor
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym) //custum constructor
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule


//ADDED IN implement copy constructor
objPos::objPos(const objPos &obj) 
{
    //allocates new memory for Pos
    pos = new Pos;
    //copies x coordinate from obj object to the x coordinate of the current object
    pos->x = obj.pos->x;
    //copies y coordinate from obj object to the y coordinate of the current object
    pos->y = obj.pos->y;
    //copiesthe symbol from obj object to the symbol of the current object
    symbol = obj.symbol;
}

//ADDED IN destructor
objPos::~objPos()
{
    //frees memory that was dynamically allocated previously
    delete(pos);
}


//ADDED IN implement copy assignment constructor
objPos& objPos::operator=(const objPos &obj)
{
    //ensures assignment operator does not proceed if they are already equal
    if(this != &obj)
    {
        //allocates new memory for pos 
        pos = new Pos;

        //creates deep copy of x and y member of struct from source obj
        pos->x = obj.pos->x;
        pos->y = obj.pos->y;
        //creates deep copy of symbol from source obj
        symbol = obj.symbol;
    }
    //returns currnet object by reference
    return *this;
}



void objPos::setObjPos(objPos o) //
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}

#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList() 
:  aList(new objPos[ARRAY_MAX_CAP]), sizeList(0), arrayCapacity(ARRAY_MAX_CAP)
{
    // Initialize the sizeArray and sizeList data members.
    //int arraySize= sizeArray;
    sizeList=0; 
    // • Allocate an array on the heap with the size specified by sizeArray.
    aList= new objPos[sizeList];
    // • The default sizeArray is 200. You may change it as needed.
    

    
}

objPosArrayList::~objPosArrayList()
{
    // Deallocate all heap data members
    // • Defense against memory leakage

    delete[] aList;
}

int objPosArrayList::getSize() const
{
    //Returns the size of the list (i.e. sizeList
    return sizeList; 
    //return 0;

}

void objPosArrayList::insertHead(objPos thisPos)
{
    //Inserting thisPos as a new objPos element to the head of the list
    //objPos *thisPos= new objPos;
    
    //sizelist is the current size of the array
    //sizearray is max size it can be 
    if (sizeList < arrayCapacity) 
    {
        for (int i = sizeList; i > 0; --i) {
            aList[i] = aList[i - 1];
        }
        aList[0] = thisPos;
        sizeList++;
    }
    
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[sizeList]=thisPos; 

    
}

void objPosArrayList::removeHead()
{
    for(int i=0; i< sizeList; i++)
    {
        aList[i]=aList[i+1];
    }
    
}

void objPosArrayList::removeTail()
{
    if(sizeList>0)
    {
        sizeList--; 
    }
    
}

objPos objPosArrayList::getHeadElement() const
{
    if(sizeList>0)
    {
        return aList[0];
    }
    
}

objPos objPosArrayList::getTailElement() const
{
    if(sizeList>0)
    {
        return aList[sizeList-1];
    }
    
}

objPos objPosArrayList::getElement(int index) const
{
    if(sizeList>0&& sizeList>index)
    {
        return aList[index];
    }
    
}
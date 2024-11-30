#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

//I changed this and initialized the members inside the class body instead of in class definiton cuz its more intuitive to me
objPosArrayList::objPosArrayList() 
{
    // Initialize the sizeArray and sizeList data members.
    //int arraySize= sizeArray;
    sizeList = 0; 
    arrayCapacity = ARRAY_MAX_CAP;
    // • Allocate an array on the heap with the size specified by sizeArray.
    aList = new objPos[arrayCapacity]; //dont think this line is right, I think it should be objPos[arrayCapacity];
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
    if (sizeList < arrayCapacity) //Checks if there is space in array i.e checks if the length of memory is > than length of list
    {
        
        //if there is enough memory, add one to list size to increase length by 1
        sizeList++;
        for (int i = sizeList; i > 0; --i) //shifts elements to the right to make space for one at the start
        {
            aList[i] = aList[i - 1];
        }

        //inserts currnet pos thisPos in the first index (i=0)
        aList[0] = thisPos;
    }
    
}

//UNCOMMENT AFTER JUST DEBUGGING
void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList < arrayCapacity) //checks if there is enough memory allocated for array list to add one more element to list
    {
    aList[sizeList] = thisPos; //adds element at END of list (at tail, or at index of list ize)
        sizeList++; //adds one unit to sizeList to account for the element we just added
    }
    
}

void objPosArrayList::removeHead()
{
    if(sizeList > 0)
    {
        for(int i = 0; i < sizeList; i++) //iterates through list and shifts values to the left, removing a value at the head
        {
            aList[i]=aList[i+1];
        }
        sizeList--;
    }
    
}

void objPosArrayList::removeTail()
{
    if(sizeList > 0) //checks that list size is greater than 0 to avoid removing element from empty list causing error
    {
        sizeList--; //simply decreases list size which automatically removes last element in list
    }
    
}

objPos objPosArrayList::getHeadElement() const
{
    if(sizeList > 0) 
    {
    return aList[0]; //returns first element
    }
    else{
        return objPos(); //IDK WHY but needs a default return value in case sizeList is less than 0.
    }
    
}

objPos objPosArrayList::getTailElement() const
{
    if(sizeList>0)
    {
    return aList[sizeList-1]; //returns last element
    }
    else{
        return objPos(); //IDK WHY but needs a default return value in case sizeList is less than 0.
    }
    
}

objPos objPosArrayList::getElement(int index) const
{
    if(index>=0 && index<sizeList)
    {
    return aList[index];
    }
    else{
        return objPos();
    }
    //ensure index does not go out of bounds

    
}
#include "Dragon.h"
#include <iostream>


Dragon::Dragon(int x, int y, int caveStart, int caveSize):Character("Dragonalot", 999,999,999,x,y, 'D', true),direction(1),emCaveStart(caveStart),emCaveSize(caveSize)
{
    //Need to correct the dragon position so it's guranteed to be infront of the cave
    //Not a great fix but it works
    yPos = caveStart + random(caveSize);
}


void Dragon::move(int maxX, int maxY)
{
    if(yPos == emCaveStart)
        direction = 1;

    if(yPos == (emCaveStart + emCaveSize-1))
        direction = -1;
 
    yPos += direction;
}
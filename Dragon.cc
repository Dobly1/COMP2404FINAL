#include "Dragon.h"

Dragon::Dragon(int x, int y):Character("Dragonalot", 999,999,999,x,y, 'D', true),direction(1)
{
    //Nothing here yet nerd
}

void Dragon::move(int maxX, int maxY)
{
    if(yPos == maxY-1)
        direction = -1;

    if(yPos == 0)
        direction = 1;

    yPos += direction;
}
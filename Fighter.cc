#include "Fighter.h"
#include <iostream>

//Creates a fighter with 0 armour, a given name, and 
Fighter::Fighter(std::string n, int x, int y,char av):Character(n, 0,5,x,y,av, true)
{
    //Whatever, good enough for now
    
}

void Fighter::move(int maxX, int maxY)
{
    //Generate a random direction
    //|0 = stay | 1 = up | 2 = down
    srand((unsigned)time(NULL));
    int randDir = random(3);
    
    std::cout << "Y RANDOM NUMber: " << randDir << std::endl;


    //Move in the correct direction
    if(randDir==1)
        yPos-=1;
    if(randDir==2)
        yPos+=1;

    xPos -= 1;

    //Y Bounds Check
    if(yPos==maxY)
        yPos -= 1;
    if(yPos==-1)
        yPos = 0;

    //X Bounds Check
    if(xPos==maxX)
        xPos-=1; bool alive;
    if(xPos==0)
        alive=false;
    
}
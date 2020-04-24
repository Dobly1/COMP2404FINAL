#include "Fighter.h"
#include <iostream>

//Creates a fighter with 0 armour, a given name, and 
Fighter::Fighter(std::string n, int x, int y,char av):Character(n, 0,5,x,y,av, true)
{
    //Nothing needed here
}


void Fighter::move(int maxX, int maxY)
{
    if(!alive)
        return;

    //Generate a random direction
    //|0 = stay | 1 = up | 2 = down
    int randDir = random(3);
    
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
        xPos-=1;
    if(xPos<=0){
        xPos = 0;
        kill();
    }
      
    
}
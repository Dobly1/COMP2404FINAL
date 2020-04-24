#include "Player.h"

Player::Player(std::string n,int s,int a, int h, int y, char av):Character(n,s,a,h,0,y,av,false)
{
    //Nothing to put here
}


void Player::move(int maxX, int maxY)
{
    //Dead players shouldn't move
    if(!alive)
        return;

    //If snared don't move for a turn and just relax
    if(snared)
    {
        snared = false;
        return;
    }


    //Generate a random direction
    //|0 = stay | 1 = up | 2 = down
    int randDir = random(3);
    
    //Move in the correct direction
    if(randDir == 1)
        yPos-=1;
    if(randDir == 2)
        yPos+=1;

    xPos += 1;

    //Y Bounds Check
    if(yPos==maxY)
        yPos -= 1;
    if(yPos==-1)
        yPos = 0;

    //X Bounds Check
    if(xPos==maxX)
        xPos-=1;

}
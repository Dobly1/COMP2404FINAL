#ifndef DRAGON_H
#define DRAGON_H

#include "Character.h"
#include "random.h"

class Dragon:public Character
{

    public:
    Dragon(int=0, int=0, int=0, int=0);
    virtual void move(int,int);

    private:
    int direction;
    int emCaveStart;
    int emCaveSize;



};



#endif
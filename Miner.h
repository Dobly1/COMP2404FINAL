#ifndef MINER_H
#define MINER_H

#include "PathFinding.h"
#include "Seeker.h"

class Miner:public Seeker
{
    public:
    Miner(PathFinding*,int,int);
    
};




#endif
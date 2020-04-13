#ifndef GAME_H
#define GAME_H

#include <list>
#include "Character.h"
#include "Array.h"

#define MAX_X 25
#define MAX_Y 5

class Game
{
    public:
    void launch();
    
    private:
    std::list<Character*> Adventurers;   
    Array<char> grid(MAX_X,MAX_Y);    


    void initFighters();
    void initPlayers();


};




#endif
#ifndef GAME_H
#define GAME_H

#include <list>
#include <iostream>
#include "unistd.h"

#include "Character.h"
#include "Player.h"
#include "Fighter.h"

#include "Borc.h"
#include "Dorc.h"
#include "Porc.h"

#include "Dragon.h"

#include "Seeker.h"
#include "Miner.h"

#include "Array.h"
#include "playerLogger.h"
#include "View.h"
#include "PathFinding.h"


using namespace std;

//Game Size
#define MAX_X1 30
#define MAX_Y1 5         

//Emerald Cave Location
#define EM_CAVE_X MAX_X1-1
#define EM_CAVE_Y_START 1
#define EM_CAVE_Y_SIZE 3

class Game
{
    public:
    Game();
    ~Game();
    void launch();

    private:    
    std::list<Character*> entities;   
    Array<char> grid;    
    playerLogger log;
    View view;

    void draw();

    void collisionCheck();
    void deathCheck();

    void spawnNewEntity();

    void initFighters();
    void initPlayers();


};




#endif
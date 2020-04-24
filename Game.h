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
#include "Snarer.h"


#include "Array.h"
#include "playerLogger.h"
#include "View.h"
#include "PathFinding.h"

using namespace std;

//IMPORTANT: COMMENT OUT THE BELOW LINE IF YOU DON'T WANT THE PROGRAM TO SLEEP EVERY LOOP ITERATION
#define SLOW

//Game Size
#define MAX_X1 25
#define MAX_Y1 5         

//Emerald Cave Location
#define EM_CAVE_X MAX_X1-1
#define EM_CAVE_Y_START 1
#define EM_CAVE_Y_SIZE 3

/*
Class: Game
Author: Callum M

Purpose:
    -Game controls dragon hollow, and all of the characters in it
    -It acts as the central class to generate new characters and control what they do
    -It communicates with the View class to display output to the console

Data Members:
    -std::list<Character*> entities
        -This is a list that keeps track of all players and monsters in the game
    -Array<char> grid
        -This is the array template that we implemented being used to store an array of chars that represent how the grid will be output
    -playerLogger log
        -This is a logger that keeps track of players and whether or not the game should be finished
    -View view
        -This is the view class that Game uses to interact with the user

Member Functions:
    -Game()
        -The default constructor to create a new Game object and initalize all of it's assets
    -~Game()
        -The destructor to deallocate all dynamically allocated memory used in the program - mainly being Character*
    -void launch()
        -The launch function that triggers the creation of all the entities as well as run's the main game loop and tells the characters to move
    -void draw()
        -This function first clears the game grid and then loops through all the entities drawing them at the appropriate
    -void collisionCheck()
        -This function checks all the entities in the list to see if any two characters are on the same coordinate, if they are then they will fight
    -void deathCheck()
        -Checks all the entities to see if any monsters have died, if they have then remove them from the list of entities. It does leave dead players
         in the list though, so the death crosses can still appear on the map
    -void spawnNewEntity()
        -Generates a random number from 0-9 to decide whether to spawn a new monster, and if it should spawn a new one then it decides which type of
         monster to create from the 5 types available
    -void initFighters()
        -Generates the dragon and adds it to the list of characters
    -void initPlayers()
        -Generates Timmy and Harold with the appropriate information and adds them to the list of entities
    -
*/

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
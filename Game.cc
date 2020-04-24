#include "Game.h"
#include <string>

Game::Game():grid(MAX_X1,MAX_Y1),log(EM_CAVE_X, EM_CAVE_Y_START, EM_CAVE_Y_SIZE),view(EM_CAVE_Y_START, EM_CAVE_Y_SIZE)
{
    //Nothing Here
}

//Deletes all the characters
Game::~Game()
{
    //Just simple algorithm for deleting everything in the list
    while(!entities.empty())
    {
        delete entities.front();
        entities.pop_front();
    }

}

void Game::launch()
{
    //Make a new random seed
    srand(time(NULL));

    //Fill the Characters list
    initPlayers();
    initFighters();


    //Make the game board initially empty
    grid.fill('~');

    list<Character*>::iterator it;

    draw();

    view.displayArr(grid);

    bool running = true;

    //Main game loop
    while(running)
    {
        grid.fill('~');
    
        for(it = entities.begin(); it != entities.end(); ++it)
        {
            (*it)->move(MAX_X1,MAX_Y1); //Move each entity
            collisionCheck(); //Make sure everyone fights every iteration
        }   
        
        //See if we should spawn a new enemy
        spawnNewEntity();

        //Finds any dead monsters and removes them from the game
        deathCheck();

        //Draw the new board into the array of cahrs
        draw();

        //So we can actually see the movement
        #ifdef SLOW
            unsigned int sleepTime = 250000;
            usleep(sleepTime);
        #endif

        //Send the array to View to be drawn
        view.displayArr(grid);

        //Ask the log if we should keep running
        log.keepRunning(running);
    }

    //If we get to this point either we have a winner or we don't, and the getWinner returns either the winning character or NULL
    Character* winner;
    log.getWinner(winner);

    //If a winner was returned then print out their name, else print the losing message
    if(winner)
    {
        std::string out = "And the winner is: ";
        out += winner->getAvatar();
        view.printStr(out);
    }
    else
    {
        std::string loseString = "Sorry no winners today :( Only losers";
        view.printStr(loseString);
    }
   
}

void Game::initPlayers()
{
    //Make our adventurers
    Character* Timmy = new Player("Timmy",3,3,17,MAX_Y1, 'T');
    Character* Harold = new Player("Harold",5,1,17,MAX_Y1, 'H');

    entities.push_back(Timmy);
    entities.push_back(Harold);

    log.subscribe(Timmy);
    log.subscribe(Harold);
}

void Game::initFighters()
{
    //Add the dragon straigh to the list of entities
    entities.push_back(new Dragon(MAX_X1-1, MAX_Y1, EM_CAVE_Y_START, EM_CAVE_Y_SIZE));
}

void Game::spawnNewEntity()
{
    
    int sP = random(10);
    
    //Not Spawn Odds
    if(sP >= 6)
        return;

   

    // 0,1 ==> Snarer Spawns
    if(sP <= 1)
    {
        PathFinding* p = new PathFinding(entities);
        entities.push_back(new Snarer(p, MAX_X1-1, MAX_Y1-1));
        return;
    }

    // 2 ==> Miner Spawns
    if(sP == 2){
        PathFinding* p = new PathFinding(entities);
        entities.push_back(new Miner(p, MAX_X1-1, MAX_Y1-1));
        return;
    }
            
    // 3 ==> Borc Spawns
    if(sP == 3){
        entities.push_back(new Borc(MAX_X1-1, MAX_Y1-1));
        return;
    }

     // 4 ==> Dorc Spawns
    if(sP == 4){
        entities.push_back(new Dorc(MAX_X1-1, MAX_Y1-1));
        return;
    }
    

    // 5 ==> Porc Spawns
    if(sP == 5){
        entities.push_back(new Porc(MAX_X1-1, MAX_Y1-1));
        return;
    }
    
}

void Game::collisionCheck()
{
    //3 Iterators needed to cover all the 
    list<Character*>::iterator it = entities.begin();
    list<Character*>::iterator it2;
    list<Character*>::iterator temp;
    int size = entities.size();

    int x1,y1,x2,y2;

    //First it iterates through every element of the list
    for(int i = 0; i<size-1; i++)
    {
        temp = it;

        //Next iterate through every other entity in the last to ensure everyone is matched
        for(it2 = temp++; it2 != entities.end(); ++it2)
        {
            (*it)->getPos(x1,y1);
            (*it2)->getPos(x2,y2);

            if(x1 == x2 && y1 == y2 && *it != *it2)
                Character::fight((*it), (*it2));
        }
        it++;
    }
}

void Game::deathCheck()
{
    list<Character*>::iterator it = entities.begin();

    while(it != entities.end())
    {
        if(!(*it)->isAlive() && (*it)->isFightable())
        {
            Character* deadCharacter = (*it);
            
            it = entities.erase(it);
            
            delete deadCharacter;
        }
            
            
        else
            ++it;
    }
}

void Game::draw()
{
    list<Character*>::iterator it;

    int x, y;

    //Draw all the players on the map to start
    for(it = entities.begin(); it != entities.end(); ++it)
    {
        (*it)->getPos(x,y);
        grid.set((*it)->getAvatar(), x, y);
    }
}
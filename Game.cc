#include "Game.h"

Game::Game():grid(MAX_X1,MAX_Y1),log(EM_CAVE_X, EM_CAVE_Y_START, EM_CAVE_Y_SIZE)
{
    //Nothing Here
}

//Deletes all the characters
Game::~Game()
{
    list<Character*>::iterator it;

    for(it = entities.begin(); it != entities.end(); ++it)
    {
        Character* deletedChar = (*it);

        it = entities.erase(it);

        delete deletedChar;
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

    int x, y;

    //Draw all the players on the map to start
    for(it = entities.begin(); it != entities.end(); ++it)
    {
        try
        {
            (*it)->getPos(x,y);
            grid.set((*it)->getAvatar(), x, y);
        }
        catch(const char* error)
        {
            cout << error << " | " << (*it)->getAvatar() << endl;
        }
        

    }

    printArrayTemp();

    bool running = true;

    //Main game loop
    while(running)
    {
        grid.fill('~');

        //See if we should spawn a new enemy
        spawnNewEntity();

        //Move all the characters to their new positions
        for(it = entities.begin(); it != entities.end(); ++it)
        {
            //Move each entity
            (*it)->move(MAX_X1,MAX_Y1);

            //Draw it on the grid
            (*it)->getPos(x,y);

            //cout << "Setting : " << (*it)->getAvatar() << " At position: ("<< x << "," << y << ")" << endl;

            grid.set((*it)->getAvatar(), x, y);
        }   

        //Preform checks
        collisionCheck();
        deathCheck();
        

        //Output the data to the screen
            

        //Sleep a little to ensure numbers are random
        unsigned int sleepTime = 250000;
        usleep(sleepTime);

        printArrayTemp();

        //Ask the log if we should keep running
        log.keepRunning(running);
    }

    Character* winner;
    log.getWinner(winner);

    if(winner)
    {
        cout << "And the winner is : " << winner->getAvatar() << "!" << endl;
    }
    else
    {
        cout << "Sorry no winners today :(, only losers" << endl;
    }
    


}

void Game::initPlayers()
{
    Character* Timmy = new Player("Timmy",3,3,15,MAX_Y1, 'T');
    Character* Harold = new Player("Harold",5,1,15,MAX_Y1, 'H');

    entities.push_back(Timmy);
    entities.push_back(Harold);

    log.subscribe(Timmy);
    log.subscribe(Harold);
}

void Game::initFighters()
{
    entities.push_back(new Dragon(MAX_X1-1, MAX_Y1));
}

void Game::spawnNewEntity()
{
    int spawnChances = random(10);

    //Not Spawn Odds
    if(spawnChances >= 6)
        return;

    //Borc
    if(spawnChances <= 1)
        entities.push_back(new Borc(MAX_X1-1, MAX_Y1-1));

    if(spawnChances <= 3)
        entities.push_back(new Dorc(MAX_X1-1, MAX_Y1-1));

    if(spawnChances <= 5)
        entities.push_back(new Porc(MAX_X1-1, MAX_Y1-1));
}

void Game::collisionCheck()
{
    list<Character*>::iterator it = entities.begin();
    list<Character*>::iterator it2;
    list<Character*>::iterator temp;
    int size = entities.size();

    int x1,y1,x2,y2;

    //First it iterates through every element of the list
    for(int i = 0; i<size-1; i++)
    {
        temp = it;

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
            Character* dedBoi = (*it);
            
            it = entities.erase(it);
            
            delete dedBoi;
        }
            
            
        else
            ++it;
    }
}

void Game::printArrayTemp()
{
    int x = grid.getX();
    int y = grid.getY();

    cout << "\033[2J\033[1;1H";

    cout << endl;

    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            cout << " " << grid.get(j,i);
        }
        cout << endl;
    } 

  
    cout << endl;
}

#include <iostream>

#include "random.h"
#include "Character.h"
#include "Fighter.h"
#include <stdlib.h>
#include <unistd.h>
#include "Player.h"
#include "Dragon.h"
#include <list>
#include "Array.h"



using namespace std;

#define MAX_X 25
#define MAX_Y 5


void print(Array<char>&);
void collisionCheck(list<Character*>&);
void deathCheck(list<Character*>&);

int main()
{
    Array<char> arr(MAX_X,MAX_Y);

    Player* Timmy = new Player("Timmy", 3, 3, 15, 1, 'T');
    Player* Harold = new Player("Harold", 5, 1, 15, 4, 'H');
    Fighter* Borc = new Fighter("Borc", MAX_X-1, 4,'B');
    Dragon* drag = new Dragon(MAX_X-1,1);

    list<Character*> chars;

    chars.push_back(Timmy);
    chars.push_back(Borc);
    chars.push_back(drag);
    chars.push_back(Harold);

    list<Character*>::iterator it;
   
    int x,y;

    for(int k = 0; k < 30; k++)
    {
        deathCheck(chars);

        for(it = chars.begin(); it != chars.end(); ++it)
        {
            Character* iterChar = (*it);

            iterChar->move(MAX_X,MAX_Y);
            iterChar->getPos(x,y);

            arr.set(iterChar->getAvatar(), x, y);
            unsigned int sleepTime = 300000;

            
        usleep(sleepTime);
        }
        //cout << "\033[2J\033[1;1H";
        print(arr);
        
        collisionCheck(chars);

        arr.reset();
       
    }
    
    //delete Borc;
    delete Timmy;
    delete Harold;
    delete drag;
}


void print(Array<char>& arr)
{
    int x = arr.getX();
    int y = arr.getY();

    for(int i=0; i<y; i++){
        cout << " Y: " << i;
        for(int j=0; j<x; j++){
            cout << " " <<arr.get(j,i);
        }
        cout << endl;
    } 

    cout << endl;
}

void collisionCheck(list<Character*>& l)
{
    list<Character*>::iterator it = l.begin();
    list<Character*>::iterator it2;
    list<Character*>::iterator temp;
    int size = l.size();

    int x1,y1,x2,y2;

    //First it iterates through every element of the list
    for(int i = 0; i<size-1; i++)
    {
        temp = it;

        for(it2 = temp++; it2 != l.end(); ++it2)
        {
            (*it)->getPos(x1,y1);
            (*it2)->getPos(x2,y2);

            if(x1 == x2 && y1 == y2 && *it != *it2)
                Character::fight((*it), (*it2));
        }
        
        it++;
    }
    
}

void deathCheck(list<Character*>& l)
{
    list<Character*>::iterator it = l.begin();

    while(it != l.end())
    {
        if(!(*it)->isAlive() && (*it)->isFightable())
        {
            Character* dedBoi = (*it);
            
            it = l.erase(it);
            
            delete dedBoi;
        }
            
            
        else
            ++it;
    }
  
}
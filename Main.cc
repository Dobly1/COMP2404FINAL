#include <iostream>
#include "Array.h"
#include "random.h"
#include "Character.h"
#include "Fighter.h"
#include <stdlib.h>
#include <unistd.h>
#include "Player.h"

using namespace std;

#define MAX_X 25
#define MAX_Y 10


void print(Array<char>&);

int main()
{
    
    Array<char> arr(MAX_X,MAX_Y);

    Player* Timmy = new Player("Timmy", 3, 3, 15, 5, 'T');

    int x,y;

    Timmy->getPos(x,y);
    arr.set(Timmy->getAvatar(), x, y);
    print(arr);
   
    for(int k = 0; k < 25; k++)
    {
        Timmy->getPos(x,y);
        Timmy->move(MAX_X,MAX_Y);

        unsigned int sleepTime = 500000;
        usleep(sleepTime);

        arr.set(Timmy->getAvatar(), x, y);
        print(arr);
        arr.reset();
    }
  

    delete Timmy;
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

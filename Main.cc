#include <iostream>
#include "Array.h"

using namespace std;


void print(Array<char>);

int main()
{
    
    Array<char> arr;
    
    try{
        arr.set('A',2,1);
    }
    catch(const char* error){
        cout << error << endl;
    }
    
    print(arr);
}

void print(Array<char> arr)
{
    int x = arr.getX();
    int y = arr.getY();

    for(int i = 0; i<y; i++)
    {
        cout << i << ": ";
        for(int j = 0; j<x; j++)
        {
            cout << " " << arr.get(j,i);
        }
        cout << endl;  
    }
}

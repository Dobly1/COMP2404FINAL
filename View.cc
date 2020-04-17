#include "View.h"

#include <iostream>
#include <iomanip>

using namespace std;

View::View(int start, int size):emYStart(start),emYSize(size)
{}

void View::displayArr(Array<char>& arr)
{
    int x,y;

    x = arr.getX();
    y = arr.getY();

    //A string of escape characters that clears the console
    #ifdef CLEAR_CONSOLE
        cout << "\033[2J\033[1;1H";
    #endif
 

    for(int i = 0; i < x+2; i++)
    {
        cout << "_";
    }

    cout << endl;

    int midPoint = (emYStart) + ( (emYSize % 2 == 0) ? emYStart/2 : (emYStart+1)/2 ); 

    for(int i = 0; i < y; i++)
    {
        cout << "|";

        for(int j = 0; j < x; j++)
        {
            char avatar = arr.get(j,i);

            //Set dragon red
            if(avatar == 'D')
                cout << "\033[31m";
            //Set timmy green
            if(avatar == 'T')
                cout << "\033[32m";
            if(avatar == 'H')
                cout << "\033[34m";
            if(avatar == 'b')
                cout << "\033[1m\033[33m";
            if(avatar == 'd')
                cout << "\033[1m\033[36m";
            if(avatar == 'p')
                cout << "\033[1m\033[35m";
            if(avatar == 's')
                cout << "\033[1m\033[40m";
            if(avatar == 'm')
                cout << "\033[1m\033[46m";
            if(avatar == '+')
                cout << "\033[1m\033[37m";


            cout << arr.get(j,i) << setw(2);

            //Reset the colour to white
            cout << "\033[0m";

        }

        if(i >= emYStart && i <= emYStart+emYSize-1){
            cout << setw(1) << "=";

            //Display the emerald as close to the middle of the cave as possible
            if(i == midPoint)
                cout << setw(1) << "*";            

        }
            
        else
            cout << setw(1) << "|";

        cout << endl;

    }

    for(int i = 0; i < x+2; i++)
    {
        cout << "-";
    }

    cout << endl;



}

void View::printStr(std::string& out)
{
    cout << "Game: " << out << endl;
}

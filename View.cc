#include "View.h"

#include <iostream>
#include <iomanip>

using namespace std;

View::View(int start, int size):emYStart(start),emYSize(size)
{}

void View::displayArr(Array<char>& arr)
{
    int x,y;

    //Get the dimmensions of the array
    x = arr.getX();
    y = arr.getY();

    //A string of escape characters that clears the console
    #ifdef CLEAR_CONSOLE
        cout << "\033[2J\033[1;1H";
    #endif
 

    //Print the upper boarded of the map
    for(int i = 0; i < x+2; i++)
    {
        cout << "_";
    }

    cout << endl;

    //Calculate when the emerald cave should be drawn to place the emerald
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
            //Harold Blue
            if(avatar == 'H')
                cout << "\033[34m";
            //Borcs Yellow
            if(avatar == 'b')
                cout << "\033[1m\033[33m";
            //Dorcs Cyan
            if(avatar == 'd')
                cout << "\033[1m\033[36m";
            //Porcs Pinks
            if(avatar == 'p')
                cout << "\033[1m\033[35m";
            //Snares White with dark background
            if(avatar == 's')
                cout << "\033[1m\033[40m";
            //Miners White with Blue background
            if(avatar == 'm')
                cout << "\033[1m\033[46m";
            //Death cross bold white
            if(avatar == '+')
                cout << "\033[1m\033[37m";


            cout << arr.get(j,i) << setw(2);

            //Reset the colour to white
            cout << "\033[0m";

        }

        //If We're inside the cave entrance also print that
        if(i >= emYStart && i <= emYStart+emYSize-1){
            cout << setw(1) << "=";

            //Display the emerald as close to the middle of the cave as possible
            if(i == midPoint)
                cout << setw(1) << "*";            

        }
            
        //Draw the right border
        else
            cout << setw(1) << "|";

        cout << endl;

    }

    //Draw the bottom border
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

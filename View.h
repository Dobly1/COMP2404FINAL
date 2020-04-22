#ifndef VIEW_H
#define VIEW_h

//#include "Character.h"
#include "Array.h"

/**IMPORTANT: COMMENT NEXT LINE OUT IF YOU DON'T WANT THE PREVIOUS BOARD CLEARED WHEN DISPLAYING GAME**/
#define CLEAR_CONSOLE

/*
Class: 
Author: Callum M

Purpose:
    -View provides an interace for Game to communicate with the console and output the array
    -It also provides a way to print strings to the console
    -NOTE**Comment out the constant defined to stop the console from being cleared on subsequence iterations

Data Members:
    -int emYStart
        -The start of the emerald cave y location 
    -int emYSize
        -The size of the emerald cave

Member Functions:
    -View(int,int)
        -The default constructor to make a new view object with the appropriate information
    -void displayArr(Array<char>&)
        -Prints the game board to the screen with the appropriate information
    -void printStr(std::string&)
        -Prints a string to the consle

*/


class View
{
    public:
    View(int=0,int=0);
    void displayArr(Array<char>&);
    void printStr(std::string&);

    private:
    int emYStart;
    int emYSize;

};

#endif

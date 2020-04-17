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
    -

Data Members:
    -

Member Functions:
    -

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

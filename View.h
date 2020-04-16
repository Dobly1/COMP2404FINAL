#ifndef VIEW_H
#define VIEW_h

//#include "Character.h"
#include "Array.h"

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

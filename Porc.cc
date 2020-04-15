#include "Porc.h"
#include "random.h"

Porc::Porc(int x,int y):Fighter("Porc",x,y,'p')
{
    int Str = random(2);

    strength = 4+Str;
}
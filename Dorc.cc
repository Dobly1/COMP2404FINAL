#include "Dorc.h"
#include "random.h"

Dorc::Dorc(int x, int y):Fighter("Dorc",x,y,'d')
{
    int Str = random(3);

    strength = 6+Str;
}
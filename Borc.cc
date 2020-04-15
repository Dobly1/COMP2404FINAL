#include "Borc.h"
#include "random.h"

Borc::Borc(int x, int y):Fighter("Borc", x, y, 'b')
{
    int Str = random(4);

    strength = 8+Str;
}
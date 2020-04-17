#include "Snarer.h"

Snarer::Snarer(PathFinding* p, int x, int y):Seeker(p, "Snarer", x, y, 's')
{
    strength = 0;
}

void Snarer::hit(Character* c)
{
    c->snare();
}
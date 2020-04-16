#include "Miner.h"

Miner::Miner(PathFinding* p, int x, int y):Seeker(p, "Miner", x, y,'m')
{
    strength = 7;
}
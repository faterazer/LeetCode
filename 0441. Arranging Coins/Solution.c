#include <math.h>

int arrangeCoins(int n)
{
    return sqrt(2) * sqrt(n + 0.25) - 0.5;
}

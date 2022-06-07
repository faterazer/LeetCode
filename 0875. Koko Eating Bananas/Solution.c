#include <math.h>

int minEatingSpeed(int* piles, int pilesSize, int h)
{
    int l = 1, r = piles[0], m;
    for (int i = 1; i < pilesSize; ++i)
        r = fmax(r, piles[i]);
    while (l <= r) {
        m = l + ((r - l) >> 1);
        int hours = 0;
        for (int i = 0; i < pilesSize; ++i)
            hours += 1 + (piles[i] - 1) / m;
        if (hours > h)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

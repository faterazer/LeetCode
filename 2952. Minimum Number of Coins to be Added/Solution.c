#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int minimumAddedCoins(int* coins, int coinsSize, int target)
{
    qsort(coins, coinsSize, sizeof(int), cmp);
    int res = 0, s = 1, i = 0;
    while (s <= target) {
        if (i < coinsSize && coins[i] <= s)
            s += coins[i++];
        else {
            s <<= 1;
            res++;
        }
    }
    return res;
}

#include <stdlib.h>

int cmp(const void* pa, const void* pb)
{
    return *(int*)pa - *(int*)pb;
}

int getMaximumConsecutive(int* coins, int coinsSize)
{
    int max_val = 0;
    qsort(coins, coinsSize, sizeof(int), cmp);
    for (int i = 0; i < coinsSize && max_val + 1 >= coins[i]; i++)
        max_val += coins[i];
    return max_val + 1;
}

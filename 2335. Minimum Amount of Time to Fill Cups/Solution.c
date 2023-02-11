#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int fillCups(int* amount, int amountSize)
{
    qsort(amount, amountSize, sizeof(int), cmp);
    if (amount[2] > amount[0] + amount[1])
        return amount[2];
    return (amount[0] + amount[1] + amount[2] + 1) / 2;
}

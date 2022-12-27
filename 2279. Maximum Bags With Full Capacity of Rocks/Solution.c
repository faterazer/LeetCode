#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks)
{
    int n = capacitySize;
    int diff[n];
    for (int i = 0; i < n; i++)
        diff[i] = capacity[i] - rocks[i];
    qsort(diff, n, sizeof(int), cmp);

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (additionalRocks < diff[i])
            break;
        additionalRocks -= diff[i];
        res += 1;
    }
    return res;
}

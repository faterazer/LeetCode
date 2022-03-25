#include <stdlib.h>

int cmp(const void *_a, const void *_b)
{
    int *a = *(int**)_a, *b = *(int**)_b;
    return b[1] - b[0] - (a[1] - a[0]);
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize)
{
    qsort(costs, costsSize, sizeof(int*), cmp);
    int n = costsSize >> 1, res = 0;
    for (int i = 0; i < n; ++i)
        res += costs[i][0] + costs[i + n][1];
    return res;
}

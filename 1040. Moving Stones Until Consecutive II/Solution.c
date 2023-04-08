#include <math.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStonesII(int* stones, int stonesSize, int* returnSize)
{
    qsort(stones, stonesSize, sizeof(int), cmp);
    int i = 0, n = stonesSize;
    int max_moves = fmax(stones[n - 1] - stones[1], stones[n - 2] - stones[0]) - n + 2;
    int min_moves = n;
    for (int j = 0; j < n; j++) {
        while (stones[j] - stones[i] + 1 > n)
            i++;
        if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1)
            min_moves = fmin(min_moves, 2);
        else
            min_moves = fmin(min_moves, n - (j - i + 1));
    }
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = min_moves;
    res[1] = max_moves;
    *returnSize = 2;
    return res;
}

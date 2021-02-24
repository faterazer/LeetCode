#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int *returnSize)
{
    int *ret = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    for (int i = 0; i < n - 1; i++)
        ret[i] = i + 1;
    ret[n - 1] = n * (1 - n) / 2;
    return ret;
}

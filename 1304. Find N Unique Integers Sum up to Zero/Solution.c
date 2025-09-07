#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int *returnSize)
{
    int *ret = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    ret[0] = -n * (n - 1) / 2;
    for (int i = 1; i < n; i++)
        ret[i] = i;
    return ret;
}

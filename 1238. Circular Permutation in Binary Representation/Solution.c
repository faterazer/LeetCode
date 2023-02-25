#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* circularPermutation(int n, int start, int* returnSize)
{
    n = 1 << n;
    int* res = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        res[i] = i ^ (i >> 1) ^ start;
    }
    return res;
}

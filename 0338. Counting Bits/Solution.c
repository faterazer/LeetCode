#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize)
{
    int* res = (int*)malloc(sizeof(int) * (n + 1));
    res[0] = 0;
    *returnSize = n;
    for (int i = 1; i <= n; i++) {
        if (i & 1)
            res[i] = res[i / 2] + 1;
        else
            res[i] = res[i / 2];
    }
    return res;
}

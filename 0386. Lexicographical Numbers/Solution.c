#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int nextNum(int x, int limit)
{
    if (x * 10 <= limit)
        return x * 10;
    while (x + 1 > limit || x % 10 == 9)
        x /= 10;
    return x + 1;
}

int* lexicalOrder(int n, int* returnSize)
{
    int* res = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    for (int i = 0, x = 1; i < n; ++i, x = nextNum(x, n))
        res[i] = x;
    return res;
}

#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *prefixesDivBy5(int *A, int ASize, int *returnSize)
{
    bool *ret = (bool*)malloc(sizeof(bool) * ASize);
    int n = 0;
    *returnSize = ASize;
    for (int i = 0; i < ASize; i++) {
        n = (n * 2 + A[i]) % 5;
        ret[i] = n == 0;
    }
    return ret;
}

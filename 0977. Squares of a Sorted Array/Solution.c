#include <math.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *A, int ASize, int *returnSize)
{
    *returnSize = ASize;
    int *ret = (int*)malloc(sizeof(int) * ASize);
    int l = 0, r = ASize - 1;
    while (l <= r) {
        if (abs(A[l]) > abs(A[r]))
            ret[--ASize] = pow(A[l++], 2);
        else
            ret[--ASize] = pow(A[r--], 2);
    }
    return ret;
}

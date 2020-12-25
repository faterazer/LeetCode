#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *fairCandySwap(int *A, int ASize, int *B, int BSize, int *returnSize)
{
    int hash[200002] = {0}, sum = 0;
    for (int i = 0; i < ASize; i++)
        sum += A[i];
    for (int i = 0; i < BSize; i++) {
        hash[B[i]] = 1;
        sum -= B[i];
    }
    int diff = sum / 2;
    int *ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < ASize; i++) {
        if (A[i] - diff >= 0 && hash[A[i] - diff]) {
            ret[0] = A[i];
            ret[1] = A[i] - diff;
        }
    }
    return ret;
}

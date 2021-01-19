#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sumEvenAfterQueries(int *A, int ASize, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
    int *ret = (int*)malloc(sizeof(int) * queriesSize);
    *returnSize = 0;
    int sum = 0;
    for (int i = 0; i < ASize; i++)
        if (!(A[i] & 1))
            sum += A[i];
    for (int i = 0; i < queriesSize; i++) {
        int val = queries[i][0], idx = queries[i][1];
        if (!(A[idx] & 1))
            sum -= A[idx];
        A[idx] += val;
        if (!(A[idx] & 1))
            sum += A[idx];
        ret[(*returnSize)++] = sum;
    }
    return ret;
}

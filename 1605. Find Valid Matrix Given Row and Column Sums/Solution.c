#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes)
{
    int m = rowSumSize, n = colSumSize, i = 0, j = 0;
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    int** res = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        res[i] = (int*)malloc(sizeof(int) * n);
        memset(res[i], 0, sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    while (i < m && j < n) {
        int tmp = res[i][j] = fmin(rowSum[i], colSum[j]);
        if ((rowSum[i] -= tmp) == 0)
            i++;
        if ((colSum[j] -= tmp) == 0)
            j++;
    }
    return res;
}

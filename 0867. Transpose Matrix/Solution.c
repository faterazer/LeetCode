#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int **A, int ASize, int *AColSize, int *returnSize, int **returnColumnSizes)
{
    int m = ASize, n = AColSize[0];
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    int **ret = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        ret[i] = (int*)malloc(sizeof(int) * m);
        (*returnColumnSizes)[i] = m;
        for (int j = 0; j < m; j++)
            ret[i][j] = A[j][i];
    }
    return ret;
}

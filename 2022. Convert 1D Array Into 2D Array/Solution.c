#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes)
{
    int **res = NULL;
    if (originalSize != m * n) {
        *returnSize = 0;
        return res;
    }
    
    res = (int**)malloc(sizeof(int*) * m);
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        res[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    int k = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = original[k++];
    return res;
}

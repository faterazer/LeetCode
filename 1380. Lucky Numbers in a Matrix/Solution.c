#include <math.h>
#include <memory.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    int m = matrixSize, n = matrixColSize[0];
    int rows[m], cols[n];
    for (int i = 0; i < m; i++)
        rows[i] = INT_MAX;
    memset(cols, 0, sizeof(cols));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rows[i] = fmin(rows[i], matrix[i][j]);
            cols[j] = fmax(cols[j], matrix[i][j]);
        }
    }
    int *res = (int*)malloc(sizeof(int) * fmin(m, n));
    *returnSize = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (rows[i] == cols[j])
                res[(*returnSize)++] = rows[i];
    res = realloc(res, sizeof(int) * (*returnSize));
    return res;
}

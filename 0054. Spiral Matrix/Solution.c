#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    if (!matrixSize || !matrixColSize[0]) {
        *returnSize = 0;
        return NULL;
    }
    int m = matrixSize, n = matrixColSize[0];
    *returnSize = m * n;
    int* res = (int*)malloc(sizeof(int) * m * n);
    int idx = 0;
    int row_beg = 0, row_end = m - 1, col_beg = 0, col_end = n - 1;
    for (; row_beg <= row_end && col_beg <= col_end; ++row_beg, --row_end, ++col_beg, --col_end) {
        for (int i = col_beg; i <= col_end; ++i)
            res[idx++] = matrix[row_beg][i];
        for (int i = row_beg + 1; i <= row_end; ++i)
            res[idx++] = matrix[i][col_end];
        for (int i = col_end - 1; i >= col_beg && row_beg < row_end; --i)
            res[idx++] = matrix[row_end][i];
        for (int i = row_end - 1; i > row_beg && col_beg < col_end; --i)
            res[idx++] = matrix[i][col_beg];
    }
    return res;
}

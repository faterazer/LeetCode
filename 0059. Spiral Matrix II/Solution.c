#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    int** res = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i)
        res[i] = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        (*returnColumnSizes)[i] = n;
    int val = 0;
    for (int up = 0, down = n - 1, left = 0, right = n - 1; up <= down && left <= right; ++up, --down, ++left, --right) {
        for (int i = left; i <= right; ++i)
            res[up][i] = ++val;
        for (int i = up + 1; i <= down; ++i)
            res[i][right] = ++val;
        for (int i = right - 1; i >= left && up < down; --i)
            res[down][i] = ++val;
        for (int i = down - 1; i > up && left < right; --i)
            res[i][left] = ++val;
    }
    return res;
}

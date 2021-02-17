#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int **nums, int numsSize, int *numsColSize, int r, int c, int *returnSize, int **returnColumnSizes)
{
    int m = numsSize, n = numsColSize[0], size = m * n;
    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = numsColSize;
        return nums;
    }
    int **ret = (int**)malloc(sizeof(int*) * r);
    *returnColumnSizes = (int*)malloc(sizeof(int) * r);
    *returnSize = r;
    for (int i = 0; i < r; i++) {
        ret[i] = (int*)malloc(sizeof(int) * c);
        (*returnColumnSizes)[i] = c;
    }
    for (int i = 0; i < size; i++)
        ret[i / c][i % c] = nums[i / n][i % n];
    return ret;
}

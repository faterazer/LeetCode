#include <math.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes)
{
    int n = gridSize;
    int** res = (int**)malloc(sizeof(int*) * (n - 2));
    *returnSize = n - 2;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (n - 2));
    for (int i = 0; i < n - 2; i++) {
        (*returnColumnSizes)[i] = n - 2;
        res[i] = (int*)calloc(n - 2, sizeof(int));
    }
    for (int i = 0; i < n - 2; i++)
        for (int j = 0; j < n - 2; j++)
            for (int x = i; x < i + 3; x++)
                for (int y = j; y < j + 3; y++)
                    res[i][j] = fmax(res[i][j], grid[x][y]);
    return res;
}

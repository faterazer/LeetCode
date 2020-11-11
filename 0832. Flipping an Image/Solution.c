#include <math.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int **A, int ASize, int *AColSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = ASize;
    *returnColumnSizes = AColSize;
    for (int i = 0; i < ASize; i++) {
        int mid = ceil(AColSize[i] / 2.0);
        for (int j = 0; j < mid; j++)
            if (A[i][j] == A[i][AColSize[i] - j - 1])
                A[i][j] = A[i][AColSize[i] - j - 1] = A[i][j] ^ 1;
    }
    return A;
}

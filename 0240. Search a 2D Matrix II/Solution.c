#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int m = matrixSize, n = matrixColSize[0];
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            ++i;
        else
            --j;
    }
    return false;
}

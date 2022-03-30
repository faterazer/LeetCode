#include <stdbool.h>

bool searchMatrix_MK1(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int m = matrixSize, n = matrixColSize[0];
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][0] > target)
            return false;
        if (matrix[i][j] < target)
            i += 1;
        else if (matrix[i][j] > target)
            j -= 1;
        else
            return true;
    }
    return false;
}


bool searchMatrix_MK2(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int m = matrixSize, n = matrixColSize[0];
    int l = 0, r = m * n - 1, mid, val;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        val = matrix[mid / n][mid % n];
        if (val < target)
            l = mid + 1;
        else if (val > target)
            r = mid - 1;
        else
            return true;
    }
    return false;
}

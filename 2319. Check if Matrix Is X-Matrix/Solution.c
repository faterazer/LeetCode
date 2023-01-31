#include <stdbool.h>

bool checkXMatrix(int** grid, int gridSize, int* gridColSize)
{
    int n = gridSize;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j || i + j == n - 1)) {
                if (!grid[i][j])
                    return false;
            } else if (grid[i][j])
                return false;
        }
    }
    return true;
}

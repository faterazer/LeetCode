#include <math.h>

int surfaceArea(int **grid, int gridSize, int *gridColSize)
{
    int N = gridSize, area = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                area += 2 + 4 * grid[i][j];
                area -= i > 0 ? fmin(grid[i][j], grid[i - 1][j]) * 2 : 0;
                area -= j > 0 ? fmin(grid[i][j], grid[i][j - 1]) * 2 : 0;
            }
        }
    }
    return area;
}

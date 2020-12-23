#include <math.h>

int projectionArea(int **grid, int gridSize, int *gridColSize)
{
    int area = 0;
    for (int i = 0; i < gridSize; i++) {
        int rowMax = 0, colMax = 0;
        for (int j = 0; j < gridSize; j++) {
            area += grid[i][j] > 0;
            rowMax = fmax(rowMax, grid[i][j]);
            colMax = fmax(colMax, grid[j][i]);
        }
        area += rowMax + colMax;
    }
    return area;
}

int islandPerimeter(int **grid, int gridSize, int *gridColSize)
{
    int perimeter = 0, repeat = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j]) {
                perimeter += 4;
                if (i > 0 && grid[i - 1][j])
                    repeat += 2;
                if (j > 0 && grid[i][j - 1])
                    repeat += 2;
            }
        }
    }
    return perimeter - repeat;
}

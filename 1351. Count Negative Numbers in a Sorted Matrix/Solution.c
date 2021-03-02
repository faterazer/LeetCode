int countNegatives(int **grid, int gridSize, int *gridColSize)
{
    int m = gridSize, n = gridColSize[0];
    int i = 0, j = n - 1, res = 0;
    while (i < m && j >= 0) {
        while (j >= 0 && grid[i][j] < 0)
            j--;
        res += n - j - 1;
        i++;
    }
    return res + (m - i) * n;
}

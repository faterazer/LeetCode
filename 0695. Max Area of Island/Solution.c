#include <math.h>

int dfs(int** grid, int m, int n, int r, int c)
{
    if (r < 0 || r >= m || c < 0 || c >= n || !grid[r][c])
        return 0;
    grid[r][c] = 0;
    return 1 + dfs(grid, m, n, r + 1, c) + dfs(grid, m, n, r - 1, c) + dfs(grid, m, n, r, c + 1) + dfs(grid, m, n, r, c - 1);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize, n = gridColSize[0], res = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j])
                res = fmax(res, dfs(grid, m, n, i, j));
    return res;
}

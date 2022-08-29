void expand(char** grid, int m, int n, int r, int c)
{
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1')
        return;
    grid[r][c] = '2';
    expand(grid, m, n, r + 1, c);
    expand(grid, m, n, r - 1, c);
    expand(grid, m, n, r, c + 1);
    expand(grid, m, n, r, c - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int res = 0;
    int m = gridSize, n = gridColSize[0];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                ++res;
                expand(grid, m, n, i, j);
            }
        }
    }
    return res;
}

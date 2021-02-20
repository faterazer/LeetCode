void gridReverse(int **grid, int m, int n, int beg, int end)
{
    int tmp;
    for (; beg < end; beg++, end--) {
        tmp = grid[beg / n][beg % n];
        grid[beg / n][beg % n] = grid[end / n][end % n];
        grid[end / n][end % n] = tmp;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int **grid, int gridSize, int *gridColSize, int k, int *returnSize, int **returnColumnSizes)
{
    int m = gridSize, n = gridColSize[0], size = m * n;
    k %= size;
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    if (!k)
        return grid;
    gridReverse(grid, m, n, 0, size - k - 1);
    gridReverse(grid, m, n, size - k, size - 1);
    gridReverse(grid, m, n, 0, size - 1);
    return grid;
}

class Solution {
    private void expand(char[][] grid, int r, int c) {
        int m = grid.length, n = grid[0].length;
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1')
            return;
        grid[r][c] = '2';
        expand(grid, r + 1, c);
        expand(grid, r - 1, c);
        expand(grid, r, c + 1);
        expand(grid, r, c - 1);
    }

    public int numIslands(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ++res;
                    expand(grid, i, j);
                }
            }
        }
        return res;
    }
}

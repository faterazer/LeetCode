class Solution {
    public int surfaceArea(int[][] grid) {
        int N = grid.length, area = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] > 0) {
                    area += 2 + grid[i][j] * 4;
                    area -= i > 0 ? Math.min(grid[i - 1][j], grid[i][j]) * 2 : 0;
                    area -= j > 0 ? Math.min(grid[i][j - 1], grid[i][j]) * 2 : 0;
                }
            }
        }
        return area;
    }
}

class Solution {
    public int projectionArea(int[][] grid) {
        int N = grid.length, area = 0;
        for (int i = 0; i < N; i++) {
            int rowMax = 0, colMax = 0;
            for (int j = 0; j < N; j++) {
                if (grid[i][j] > 0) {
                    area++;
                }
                rowMax = Math.max(rowMax, grid[i][j]);
                colMax = Math.max(colMax, grid[j][i]);
            }
            area += rowMax + colMax;
        }
        return area;
    }
}

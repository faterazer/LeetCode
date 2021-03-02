class Solution {
    public int countNegatives(int[][] grid) {
        int i = 0, j = grid[0].length - 1, res = 0;
        while (i < grid.length && j >= 0) {
            while (j >= 0 && grid[i][j] < 0) {
                j--;
            }
            res += grid[0].length - j - 1;
            i++;
        }
        return res + (grid.length - i) * grid[0].length;
    }
}

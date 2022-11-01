class Solution {
    public int[] findBall(int[][] grid) {
        int n = grid[0].length;
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            int j = i;
            for (int[] row : grid) {
                int k = j;
                j += row[j];
                if (j < 0 || j >= n || row[j] != row[k]) {
                    j = -1;
                    break;
                }
            }
            res[i] = j;
        }
        return res;
    }
}

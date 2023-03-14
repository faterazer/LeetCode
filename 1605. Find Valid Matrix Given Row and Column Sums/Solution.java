class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int m = rowSum.length, n = colSum.length, i = 0, j = 0;
        int[][] res = new int[m][n];
        while (i < m && j < n) {
            int temp = res[i][j] = Math.min(rowSum[i], colSum[j]);
            if ((rowSum[i] -= temp) == 0) {
                ++i;
            }
            if ((colSum[j] -= temp) == 0) {
                ++j;
            }
        }
        return res;
    }
}

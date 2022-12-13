import java.util.Arrays;

class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int[][] dp = new int[n][n];
        System.arraycopy(matrix[n - 1], 0, dp[n - 1], 0, n);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j] + Math.min(dp[i + 1][j], Math.min(j == 0 ? Integer.MAX_VALUE : dp[i + 1][j - 1], j == n - 1 ? Integer.MAX_VALUE : dp[i + 1][j + 1]));
            }
        }
        return Arrays.stream(dp[0]).min().orElse(0);
    }
}

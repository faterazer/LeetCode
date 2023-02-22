class Solution {
    public int dieSimulator(int n, int[] rollMax) {
        int m = rollMax.length, MOD = (int) (1e9 + 7);
        int[][] dp = new int[n][m];
        int[] s = new int[n];
        for (int j = 0; j < m; j++) {
            dp[0][j] = 1;
        }
        s[0] = m;
        for (int i = 1; i < n; i++) {
            s[i] = 0;
            for (int j = 0; j < m; j++) {
                dp[i][j] = s[i - 1];
                if (i == rollMax[j]) {
                    --dp[i][j];
                } else if (i > rollMax[j]) {
                    dp[i][j] = (dp[i][j] - s[i - rollMax[j] - 1] + dp[i - rollMax[j] - 1][j]) % MOD;
                }
                dp[i][j] = (dp[i][j] + MOD) % MOD;
                s[i] = (s[i] + dp[i][j]) % MOD;
            }
        }
        return s[n - 1];
    }
}

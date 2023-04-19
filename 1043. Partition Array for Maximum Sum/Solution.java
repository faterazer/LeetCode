class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int[] dp = new int[k];
        for (int i = 1; i <= arr.length; i++) {
            int maxVal = 0, best = 0;
            for (int j = 1; j <= k && i - j >= 0; j++) {
                maxVal = Math.max(maxVal, arr[i - j]);
                best = Math.max(best, dp[(i - j) % k] + maxVal * j);
            }
            dp[i % k] = best;
        }
        return dp[arr.length % k];
    }
}

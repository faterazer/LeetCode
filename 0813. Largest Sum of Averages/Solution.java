class Solution {
    public double largestSumOfAverages(int[] nums, int k) {
        int n = nums.length;
        double[] preSum = new double[n + 1];
        for (int i = 0; i < nums.length; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        double[] dp = new double[n + 1];
        for (int i = 1; i <= n; i++) {
            dp[i] = preSum[i] / i;
        }
        for (int i = 2; i <= k; i++) {
            for (int j = n; j >= i; j--) {
                for (int w = 0; w < j; w++) {
                    dp[j] = Math.max(dp[j], dp[w] + (preSum[j] - preSum[w]) / (j - w));
                }
            }
        }
        return dp[n];
    }
}

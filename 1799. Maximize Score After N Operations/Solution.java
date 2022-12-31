class Solution {
    public int maxScore(int[] nums) {
        int n = 1 << nums.length;
        int[][] gcd_temp = new int[nums.length][nums.length];
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                gcd_temp[i][j] = gcd(nums[i], nums[j]);
            }
        }

        int[] dp = new int[n];
        for (int i = 1; i < n; i++) {
            int cnt = Integer.bitCount(i);
            if (cnt % 2 == 1) {
                continue;
            }

            for (int j = 0; j < nums.length; j++) {
                if (((i >> j) & 1) != 0) {
                    for (int k = j + 1; k < nums.length; k++) {
                        if (((i >> k) & 1) != 0) {
                            dp[i] = Math.max(dp[i], dp[i ^ (1 << j) ^ (1 << k)] + cnt / 2 * gcd_temp[j][k]);
                        }
                    }
                }
            }
        }
        return dp[n - 1];
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

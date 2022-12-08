import java.util.Arrays;

class Solution {
    public int closestCost(int[] baseCosts, int[] toppingCosts, int target) {
        int minBaseCost = Arrays.stream(baseCosts).min().orElse(0);
        if (minBaseCost > target) {
            return minBaseCost;
        }

        int margin = Integer.MAX_VALUE;
        boolean[] dp = new boolean[target + 1];
        for (int baseCost : baseCosts) {
            if (baseCost <= target) {
                dp[baseCost] = true;
            } else {
                margin = Math.min(margin, baseCost - target);
            }
        }

        for (int cost : toppingCosts) {
            for (int count = 0; count < 2; count++) {
                for (int i = target; i > 0; i--) {
                    if (dp[i]) {
                        if (i + cost > target) {
                            margin = Math.min(margin, i + cost - target);
                        } else {
                            dp[i + cost] = true;
                        }
                    }
                }
            }
        }

        for (int i = target; i >= target - margin; i--) {
            if (dp[i]) {
                return i;
            }
        }
        return target + margin;
    }
}

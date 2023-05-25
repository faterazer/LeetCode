import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;
        if (n < d) {
            return -1;
        }
        int[] dp = new int[n];
        for (int i = 0, maxVal = 0; i < n; i++) {
            maxVal = Math.max(jobDifficulty[i], maxVal);
            dp[i] = maxVal;
        }
        for (int i = 1; i < d; i++) {
            Deque<int[]> stack = new ArrayDeque<>();
            int[] nextDp = new int[n];
            for (int j = i; j < n; j++) {
                int preMin = dp[j - 1];
                while (!stack.isEmpty() && jobDifficulty[stack.peek()[0]] < jobDifficulty[j]) {
                    preMin = Math.min(preMin, stack.pop()[1]);
                }
                if (stack.isEmpty()) {
                    nextDp[j] = preMin + jobDifficulty[j];
                } else {
                    nextDp[j] = Math.min(nextDp[stack.peek()[0]], preMin + jobDifficulty[j]);
                }
                stack.push(new int[]{j, preMin});
            }
            dp = nextDp;
        }
        return dp[n - 1];
    }
}

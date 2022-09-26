import java.util.Arrays;

class Solution {
    /**
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    public int rotatedDigits_MK1(int n) {
        // dp[i] = 0, invalid number
        // dp[i] = 1, valid and same number
        // dp[i] = 2, valid and different number

        int[] dp = new int[n + 1];
        int count = 0;
        for (int i = 0; i < dp.length; i++) {
            if (i == 0 || i == 1 || i == 8) {
                dp[i] = 1;
            } else if (i == 2 || i == 5 || i == 6 || i == 9) {
                dp[i] = 2;
                ++count;
            } else {
                int a = dp[i % 10], b = dp[i / 10];
                if (a == 1 && b == 1) {
                    dp[i] = 1;
                } else if (a >= 1 && b >= 1) {
                    dp[i] = 2;
                    ++count;
                }
            }
        }
        return count;
    }

    /**
     * Time complexity: O(lgn)
     * Space complexity: O(lgn)
     */
    public int rotatedDigits_MK2(int n) {
        String s = String.valueOf(n);
        int[][] dp = new int[s.length()][2];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return dfs(s, 0, true, 0, dp);
    }

    private int dfs(String s, int pos, boolean isLimit, int hasDiff, int[][] memo) {
        if (pos == s.length()) {
            return hasDiff;
        }
        if (!isLimit && memo[pos][hasDiff] > -1) {
            return memo[pos][hasDiff];
        }
        int limit = isLimit ? s.charAt(pos) - '0' : 9, res = 0;
        for (int i = 0; i <= limit; i++) {
            if (check[i] != -1) {
                res += dfs(s, pos + 1, isLimit && i == limit, hasDiff != 0 || check[i] == 1 ? 1 : 0, memo);
            }
        }
        if (!isLimit) {
            memo[pos][hasDiff] = res;
        }
        return res;
    }

    // 0: invalid number. 1: valid and same number. 2: valid and different number.
    static private final int[] check = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
}

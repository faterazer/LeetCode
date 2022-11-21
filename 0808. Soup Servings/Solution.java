import java.util.Arrays;

class Solution {
    private double dfs(int a, int b, double[][] memo) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        } else if (a <= 0) {
            return 1.0;
        } else if (b <= 0) {
            return 0.0;
        }
        if (memo[a][b] < 0) {
            memo[a][b] = 0.25 * (dfs(a - 4, b, memo) + dfs(a - 3, b - 1, memo) + dfs(a - 2, b - 2, memo) + dfs(a - 1, b - 3, memo));
        }
        return memo[a][b];
    }


    public double soupServings(int n) {
        n = (int) Math.ceil(n / 25.0);
        if (n >= 179) {
            return 1.0;
        }
        double[][] memo = new double[179][179];
        for (double[] row : memo) {
            Arrays.fill(row, -1);
        }
        return dfs(n, n, memo);
    }
}

class Solution {
    public int diagonalSum(int[][] mat) {
        int sum = 0, n = mat.length;
        for (int i = 0; i < n; i++) {
            sum += mat[i][i] + mat[i][n - 1 - i];
        }
        return n % 2 == 1 ? sum - mat[n / 2][n / 2] : sum;
    }
}

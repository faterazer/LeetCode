class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int val = 1;
        while (up <= down && left <= right) {
            for (int i = left; i <= right; ++i) {
                res[up][i] = val++;
            }
            for (int i = up + 1; i <= down; ++i) {
                res[i][right] = val++;
            }
            for (int i = right - 1; i >= left && up < down; --i) {
                res[down][i] = val++;
            }
            for (int i = down - 1; i > up && left < right; --i) {
                res[i][left] = val++;
            }
            ++up;
            --down;
            ++left;
            --right;
        }
        return res;
    }
}

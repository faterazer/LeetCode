class Solution {
    private int dfs(int row, int n, int colUsed, int dia1Used, int dia2Used) {
        if (row == n) {
            return 1;
        }
        int res = 0, pos = 1 << n;
        for (int i = 0; i < n; ++i) {
            pos >>= 1;
            if ((colUsed & pos) == 0 && (dia1Used & pos) == 0 && (dia2Used & pos) == 0) {
                res += dfs(row + 1, n, colUsed | pos, (dia1Used | pos) << 1, (dia2Used | pos) >> 1);
            }
        }
        return res;
    }

    public int totalNQueens(int n) {
        return dfs(0, n, 0, 0, 0);
    }
}

class Solution {
public:
    int totalNQueens(int n)
    {
        return dfs(0, n, 0, 0, 0);
    }

private:
    int dfs(int row, int n, int col_used, int dia1_used, int dia2_used)
    {
        if (row == n)
            return 1;
        int res = 0, pos = 1 << n;
        for (int i = 0; i < n; ++i) {
            pos >>= 1;
            if (col_used & pos || dia1_used & pos || dia2_used & pos)
                continue;
            res += dfs(row + 1, n, col_used | pos, (dia1_used | pos) << 1, (dia2_used | pos) >> 1);
        }
        return res;
    }
};

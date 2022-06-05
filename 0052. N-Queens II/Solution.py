class Solution:
    def totalNQueens(self, n: int) -> int:
        def dfs(row: int, n: int, col_used: int, dia1_used: int, dia2_used: int) -> int:
            if row == n:
                return 1
            res, pos = 0, 1 << n
            for _ in range(n):
                pos >>= 1
                if col_used & pos or dia1_used & pos or dia2_used & pos:
                    continue
                res += dfs(row + 1, n, col_used | pos, (dia1_used | pos) << 1, (dia2_used | pos) >> 1)
            return res
        
        return dfs(0, n, 0, 0, 0)
        
from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        board = []

        def helper(col_used: int, dia1_used: int, dia2_used: int) -> None:
            if len(board) == n:
                res.append(board.copy())
                return
            line = ['.'] * n
            pos = 1 << n
            for i in range(n):
                pos >>= 1
                if col_used & pos or dia1_used & pos or dia2_used & pos:
                    continue
                line[i] = 'Q'
                board.append(''.join(line))
                helper(col_used | pos, (dia1_used | pos)
                       << 1, (dia2_used | pos) >> 1)
                board.pop()
                line[i] = '.'

        helper(0, 0, 0)
        return res

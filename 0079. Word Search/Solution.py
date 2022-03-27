from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])

        def dfs(board: List[List[str]], r: int, c: int, word: str, idx: int) -> bool:
            if idx == len(word):
                return True
            if r < 0 or r >= m or c < 0 or c >= n or board[r][c] != word[idx]:
                return False
            board[r][c] = '#'
            res = dfs(board, r + 1, c, word, idx + 1) or dfs(board, r - 1, c, word, idx + 1) or dfs(board, r, c + 1, word, idx + 1) or dfs(board, r, c - 1, word, idx + 1)
            board[r][c] = word[idx]
            return res

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0] and dfs(board, i, j, word, 0):
                    return True
        return False

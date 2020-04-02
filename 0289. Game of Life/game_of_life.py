from typing import List, Tuple


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m, n = len(board), len(board[0])
        
        def neighbor(i: int, j: int) -> Tuple[int, int]:
            directions = ((i-1, j-1), (i-1, j), (i-1, j+1), (i, j-1), (i, j+1), (i+1, j-1), (i+1, j), (i+1, j+1))
            for ni, nj in directions:
                if 0 <= ni < m and 0 <= nj < n:
                    yield (ni, nj)

        for i in range(m):
            for j in range(n):
                lives = 0
                for ni, nj in neighbor(i, j):
                    if board[ni][nj] > 0:
                        lives += 1
                if board[i][j] and (lives < 2 or lives > 3):
                    board[i][j] = 2
                elif not board[i][j] and lives == 3:
                    board[i][j] = -1

        for i in range(m):
            for j in range(n):
                if board[i][j] == 2:
                    board[i][j] = 0
                elif board[i][j] == -1:
                    board[i][j] = 1

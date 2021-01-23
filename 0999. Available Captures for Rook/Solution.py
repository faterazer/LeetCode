from typing import List


class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        x, y, n = 0, 0, len(board)
        for i in range(n):
            for j in range(n):
                if board[i][j] == 'R':
                    x, y = i, j
                    break
            if board[x][y] == 'R':
                break
        
        direction = ((1, 0), (-1, 0), (0, 1), (0, -1))
        ret = 0
        for d in direction:
            nx, ny = x + d[0], y + d[1]
            while 0 <= nx < n and 0 <= ny < n and board[nx][ny] != 'B':
                if board[nx][ny] == 'p':
                    ret += 1
                    break
                nx += d[0]
                ny += d[1]
        return ret

from collections import deque
from typing import List


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        visited = [False] * (n * n + 1)
        queue = deque([1])
        steps = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                pos = queue.popleft()
                for i in range(pos + 1, min(pos + 7, n * n + 1)):
                    if visited[i]:
                        continue
                    visited[i] = True
                    if i == n * n:
                        return steps + 1

                    r, c = divmod(i - 1, n)
                    if r & 1:
                        c = n - 1 - c
                    r = n - 1 - r

                    if board[r][c] != -1 and board[r][c] == n * n:
                        return steps + 1
                    if board[r][c] == -1:
                        queue.append(i)
                    else:
                        queue.append(board[r][c])
            steps += 1
        return -1

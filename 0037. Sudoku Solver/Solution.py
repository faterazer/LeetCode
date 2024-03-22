from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows, cols, boxes = [0] * 9, [0] * 9, [0] * 9
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    bit = 1 << (int(board[i][j]) - 1)
                    rows[i] |= bit
                    cols[j] |= bit
                    boxes[i // 3 * 3 + j // 3] |= bit

        def dfs(i: int, j: int) -> bool:
            if j == 9:
                i, j = i + 1, 0

            while i < 9 and board[i][j] != ".":
                j += 1
                if j == 9:
                    i, j = i + 1, 0

            if i == 9:
                return True

            for k in range(9):
                bit = 1 << k
                if rows[i] & bit or cols[j] & bit or boxes[i // 3 * 3 + j // 3] & bit:
                    continue

                board[i][j] = str(k + 1)
                rows[i] |= bit
                cols[j] |= bit
                boxes[i // 3 * 3 + j // 3] |= bit

                if dfs(i, j + 1):
                    return True

                boxes[i // 3 * 3 + j // 3] ^= bit
                cols[j] ^= bit
                rows[i] ^= bit
                board[i][j] = "."

            return False

        dfs(0, 0)

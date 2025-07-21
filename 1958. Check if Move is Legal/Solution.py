class Solution:
    def checkMove(self, board: list[list[str]], rMove: int, cMove: int, color: str) -> bool:
        m, n = len(board), len(board[0])
        for dx, dy in (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1):
            x, y = rMove + dx, cMove + dy
            if x < 0 or x >= m or y < 0 or y >= n or board[x][y] == "." or board[x][y] == color:
                continue
            while True:
                x += dx
                y += dy
                if x < 0 or x >= m or y < 0 or y >= n or board[x][y] == ".":
                    break
                if board[x][y] == color:
                    return True
        return False

from typing import List


class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        row, col, dia = [0] * 3, [0] * 3, [0] * 2
        for i, m in enumerate(moves):
            val = 1 if i % 2 == 0 else -1
            row[m[0]] += val
            col[m[1]] += val
            if m[0] == m[1]:
                dia[0] += val
            if m[0] + m[1] == 2:
                dia[1] += val
            if row[m[0]] == 3 or col[m[1]] == 3 or dia[0] == 3 or dia[1] == 3:
                return "A"
            elif row[m[0]] == -3 or col[m[1]] == -3 or dia[0] == -3 or dia[1] == -3:
                return "B"
        return "Draw" if len(moves) == 9 else "Pending"

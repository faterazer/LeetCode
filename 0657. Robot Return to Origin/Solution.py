class Solution:
    def judgeCircle_MK1(self, moves: str) -> bool:
        x = y = 0
        for move in moves:
            if move == 'U':
                x += 1
            elif move == 'D':
                x -= 1
            elif move == 'R':
                y += 1
            else:
                y -= 1
        return x == y == 0

    def judgeCircle_MK2(self, moves: str) -> bool:
        return (moves.count('U') == moves.count('D')) and (moves.count('R') == moves.count('L'))

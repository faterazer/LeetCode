class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        directions = ((0, 1), (1, 0), (0, -1), (-1, 0))
        x = y = d = 0
        for c in instructions:
            if c == "L":
                d = (d + 3) % 4
            elif c == "R":
                d = (d + 1) % 4
            else:
                x, y = x + directions[d][0], y + directions[d][1]
        return x == 0 and y == 0 or d > 0

from typing import List


class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        i = j = 0
        for s in commands:
            match s[0]:
                case "U":
                    i -= 1
                case "D":
                    i += 1
                case "L":
                    j -= 1
                case "R":
                    j += 1
        return i * n + j

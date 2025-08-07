from math import sqrt


class Solution:
    def canAliceWin(self, n: int) -> bool:
        x = (21 - sqrt(441 - n * 8)) // 2
        return x % 2 > 0

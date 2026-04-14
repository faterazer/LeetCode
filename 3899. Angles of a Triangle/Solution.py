from math import acos, degrees


class Solution:
    def internalAngles(self, sides: list[int]) -> list[float]:
        sides.sort()
        a, b, c = sides
        if a + b <= c:
            return []
        A = degrees(acos((b * b + c * c - a * a) / (b * c * 2)))
        B = degrees(acos((a * a + c * c - b * b) / (a * c * 2)))
        return [A, B, 180 - A - B]

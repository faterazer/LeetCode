from math import floor, isqrt, sqrt


class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        def height(x: int, y: int) -> int:
            odd = isqrt(x)
            even = floor((sqrt(1 + 4 * y) - 1) / 2)
            return even * 2 + 1 if odd > even else odd * 2

        return max(height(red, blue), height(blue, red))

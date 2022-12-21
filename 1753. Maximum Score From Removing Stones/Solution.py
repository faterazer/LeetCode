class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        s = a + b + c
        return min(s - max(a, b, c), s // 2)

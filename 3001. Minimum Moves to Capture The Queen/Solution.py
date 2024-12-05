class Solution:
    def minMovesToCaptureTheQueen(self, a: int, b: int, c: int, d: int, e: int, f: int) -> int:
        if a == e:
            return 2 if c == e and min(b, f) < d < max(b, f) else 1
        if b == f:
            return 2 if d == f and min(a, e) < c < max(a, e) else 1
        if abs(c - e) == abs(d - f):
            return 2 if abs(a - e) == abs(b - f) and min(c, e) < a < max(c, e) and min(d, f) < b < max(d, f) else 1
        return 2

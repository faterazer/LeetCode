class Solution:
    def countTriples(self, n: int) -> int:
        res = 0
        for a in range(3, n + 1):
            for b in range(a, n + 1):
                c = int((a * a + b * b) ** 0.5)
                if c <= n and c * c == a * a + b * b:
                    res += 1 if a == b else 2
        return res

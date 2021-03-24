class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        res = 0
        for x in range(start, start + n * 2, 2):
            res ^= x
        return res

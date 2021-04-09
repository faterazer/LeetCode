class Solution:
    def xorOperation_MK1(self, n: int, start: int) -> int:
        res = 0
        for x in range(start, start + n * 2, 2):
            res ^= x
        return res

    def xorOPeration_MK2(self, n: int, start: int) -> int:
        def helper(n: int, start: int) -> int:
            if start & 1:
                return (start - 1) ^ helper(n + 1, start - 1)
            if n % 2:
                return n >> 1 & 1 ^ (start + n - 1)
            else:
                return n >> 1 & 1

        res = helper(n, start >> 1) << 1
        if n & start & 1:
            res |= 1
        return res

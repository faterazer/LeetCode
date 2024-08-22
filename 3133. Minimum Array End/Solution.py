class Solution:
    def minEnd(self, n: int, x: int) -> int:
        t = ~x
        n -= 1
        while n:
            low_bit = t & -t
            x |= (n & 1) * low_bit
            t ^= low_bit
            n >>= 1
        return x

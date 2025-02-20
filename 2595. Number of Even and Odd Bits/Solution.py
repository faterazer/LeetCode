class Solution:
    def evenOddBit(self, n: int) -> list[int]:
        MASK = 0x55555555
        return [(n & MASK).bit_count(), (n & ~MASK).bit_count()]

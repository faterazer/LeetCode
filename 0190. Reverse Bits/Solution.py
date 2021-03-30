class Solution:
    def reverseBits_MK1(self, n: int) -> int:
        res = bin(n)[2:][::-1]
        res += (32 - len(res)) * '0'
        return int(res, base=2)
        
    def reverseBits_MK2(self, n: int) -> int:
        res = 0
        for i in range(32):
            res <<= 1
            res |= n & 1
            n >>= 1
        return res

    def reverseBits_MK3(self, n: int) -> int:
        n = (n >> 16) | (n << 16)
        n = ((n & 0x00ff00ff) << 8) | ((n & 0xff00ff00) >> 8)
        n = ((n & 0x0f0f0f0f) << 4) | ((n & 0xf0f0f0f0) >> 4)
        n = ((n & 0x33333333) << 2) | ((n & 0xcccccccc) >> 2)
        n = ((n & 0x55555555) << 1) | ((n & 0xaaaaaaaa) >> 1)
        return n

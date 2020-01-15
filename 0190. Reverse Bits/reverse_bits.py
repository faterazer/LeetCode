class Solution:
    def reverseBits_MK1(self, n: int) -> int:
        res = bin(n)[2:][::-1]
        res += (32 - len(res)) * '0'
        return int(res, base=2)
        
    def reverseBits_MK2(self, n: int) -> int:
        res = 0
        for i in range(32):
            if n & (1 << i):
                res |= 1 << (31 - i)
        return res

class Solution:
    def hammingWeight_MK1(self, n: int) -> int:
        return bin(n).count('1')

    def hammingWeight_MK2(self, n: int) -> int:
        res = 0
        while n:
            n &= n - 1
            res += 1
        return res
        
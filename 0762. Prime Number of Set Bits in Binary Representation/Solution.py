class Solution:
    def countPrimeSetBits(self, L: int, R: int) -> int:
        return sum(665772 >> bin(i).count('1') & 1 for i in range(L, R+1))

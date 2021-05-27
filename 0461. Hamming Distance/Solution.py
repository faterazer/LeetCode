class Solution:
    def hammingDistance_MK1(self, x: int, y: int) -> int:
        return bin(x ^ y).count('1')

    def hammingDistance_MK2(self, x: int, y: int) -> int:
        x ^= y
        distance = 0
        while x:
            distance += 1
            x &= (x - 1)
        return distance

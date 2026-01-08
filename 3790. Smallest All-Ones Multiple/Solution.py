class Solution:
    def minAllOneMultiple(self, k: int) -> int:
        if k % 2 == 0 or k % 5 == 0:
            return -1
        x = 1
        for i in range(1, k + 1):
            if x % k == 0:
                return i
            x = (x * 10 + 1) % k
        return -1

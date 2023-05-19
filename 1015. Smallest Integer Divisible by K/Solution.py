from itertools import count


class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k % 2 == 0 or k % 5 == 0:
            return -1
        x = 1 % k
        for i in count(1):
            if x == 0:
                return i
            x = (x * 10 + 1) % k

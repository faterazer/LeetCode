import math
from typing import List


class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        res = 0
        cnt = [0] * 10
        for x in nums:
            for y, c in enumerate(cnt):
                if c and math.gcd(x % 10, y) == 1:
                    res += c
            while x > 9:
                x //= 10
            cnt[x] += 1
        return res

from collections import Counter
from typing import List


class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        cnt = Counter(x & y for x in nums for y in nums)
        res = 0
        for x in nums:
            x = x ^ 0xFFFF
            i = x
            while i:
                res += cnt[i]
                i = (i - 1) & x
            res += cnt[0]
        return res

from collections import Counter
from typing import List


class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        res = -1
        cnt = Counter()
        for x in nums:
            if x % 2:
                continue
            cnt[x] += 1
            if cnt[x] > cnt[res] or cnt[x] == cnt[res] and x < res:
                res = x
        return res

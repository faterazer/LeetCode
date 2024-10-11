from collections import Counter
from typing import List


class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        cnt1 = Counter(x // k for x in nums1 if x % k == 0)
        if not cnt1:
            return 0

        ans, lim = 0, max(cnt1.keys()) + 1
        for x, c in Counter(nums2).items():
            for y in range(x, lim, x):
                if y in cnt1:
                    ans += cnt1[y] * c
        return ans

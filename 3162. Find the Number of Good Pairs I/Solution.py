from collections import Counter
from typing import List


class Solution:
    def numberOfPairs_MK1(self, nums1: List[int], nums2: List[int], k: int) -> int:
        return sum(x % (y * k) == 0 for x in nums1 for y in nums2)

    def numberOfPairs_MK2(self, nums1: List[int], nums2: List[int], k: int) -> int:
        cnt1 = Counter(x // k for x in nums1 if x % k == 0)
        if not cnt1:
            return 0

        ans, mx = 0, max(cnt1.keys())
        for x, c in Counter(nums2).items():
            ans += sum(cnt1[y] * c for y in range(x, mx + 1, x))
        return ans

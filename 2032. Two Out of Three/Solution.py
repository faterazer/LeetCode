from collections import defaultdict
from typing import List


class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        cnt = defaultdict(int)
        for i, arr in enumerate((nums1, nums2, nums3)):
            for x in arr:
                cnt[x] |= 1 << i
        return [k for k, v in cnt.items() if v & (v - 1)]

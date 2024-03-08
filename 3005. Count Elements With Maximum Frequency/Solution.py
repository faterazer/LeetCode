from collections import Counter
from typing import List


class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        max_freq = cnt.most_common(1)[0][1]
        return sum(v for v in cnt.values() if v == max_freq)

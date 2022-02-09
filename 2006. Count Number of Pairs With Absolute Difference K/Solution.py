from collections import Counter
from typing import List


class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        counter = Counter(nums)
        return sum(counter.get(num + k, 0) * freq for num, freq in counter.items())

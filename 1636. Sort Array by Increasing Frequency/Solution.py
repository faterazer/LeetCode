import collections
from typing import List


class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        counter = collections.Counter(nums)
        return sorted(nums, key=lambda x: (counter[x], -x))

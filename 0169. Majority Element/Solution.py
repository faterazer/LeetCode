from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate, count = None, 0
        for num in nums:
            if not count:
                candidate = num
            count += (1 if num == candidate else -1)
        return candidate

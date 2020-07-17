from typing import List


class Solution:
    def findRelativeRanks(self, nums: List[int]) -> List[str]:
        sort = sorted(nums, reverse=True)
        rank = ['Gold Medal', 'Silver Medal', 'Bronze Medal'] + [str(i + 1) for i in range(3, len(nums))]
        return map(dict(zip(sort, rank)).get, nums)

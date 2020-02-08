from typing import List


class Solution:
    def containsNearbyDuplicate_MK1(self, nums: List[int], k: int) -> bool:
        '''
        Use dict
        '''
        memo = {}
        for i, num in enumerate(nums):
            if num in memo and i - memo[num] <= k:
                return True
            memo[num] = i
        return False

    def containsNearbyDuplicate_MK2(self, nums: List[int], k: int) -> bool:
        '''
        Use set
        '''
        memo = set()
        for i, num in enumerate(nums):
            if i > k:
                memo.discard(nums[i - k - 1])
            if num in memo:
                return True
            memo.add(num)
        return False

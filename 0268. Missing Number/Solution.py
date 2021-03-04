from typing import List


class Solution:
    def missingNumber_MK1(self, nums: List[int]) -> int:
        '''
        XOR.
        Time Complexity: O(n)
        Space Complexity: O(1)
        '''
        missing = len(nums)
        for i, n in enumerate(nums):
            missing ^= i ^ n
        return missing

    def missingNumber_MK2(self, nums: List[int]) -> int:
        '''
        Gauss' Formula
        '''
        ans = len(nums) * (len(nums) + 1) // 2
        for n in nums:
            ans -= n
        return ans

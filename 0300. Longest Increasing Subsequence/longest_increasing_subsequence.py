import bisect
from typing import List


class Solution:
    def lengthOfLIS_MK1(self, nums: List[int]) -> int:
        '''
        Dynamic Programming
        Time Complexity: O(n^2)
        Space complexity: O(n)
        '''
        if not nums:
            return 0

        dp = [0] * len(nums)
        for i in range(len(nums)):
            dp[i] = 1
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[j] + 1, dp[i])
        return max(dp)

    def lengthOfLIS_MK2(self, nums: List[int]) -> int:
        '''
        Dynamic Programming with Binary Search
        Time Complexity: O(nlgn)
        Space Complexity: O(n)
        '''
        dp = []
        for num in nums:
            index = bisect.bisect_left(dp, num)
            if index == len(dp):
                dp.append(num)
            else:
                dp[index] = num
        return len(dp)

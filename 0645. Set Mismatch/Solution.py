from typing import List


class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        '''
        Time complexity: O(n).
        Space complexity: O(1).
        '''
        dup, total, n = 0, 0, len(nums)
        for num in nums:
            if nums[abs(num) - 1] < 0:
                dup = abs(num)
            else:
                nums[abs(num) - 1] *= -1
            total += abs(num)
        return [dup, (1 + n) * n // 2 - total + dup]

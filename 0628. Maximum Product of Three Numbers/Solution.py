import heapq
from typing import List


class Solution:
    def maximumProduct_MK1(self, nums: List[int]) -> int:
        '''
        Time complexity: O(nlgn)
        Space complexity: O(1)
        '''
        nums.sort()
        return max(nums[-1] * nums[-2] * nums[-3], nums[0] * nums[1] * nums[-1])

    def maximumProduct_MK2(self, nums: List[int]) -> int:
        '''
        Time complexity: O(n)
        Space complexity: (1)
        '''
        a, b = heapq.nlargest(3, nums), heapq.nsmallest(2, nums)
        return max(a[0] * a[1] * a[2], a[0] * b[0] * b[1])

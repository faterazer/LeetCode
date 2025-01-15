import heapq
from typing import List


class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        ans = 0
        while nums[0] < k:
            x = heapq.heappop(nums)
            heapq.heapreplace(nums, nums[0] + x * 2)
            ans += 1
        return ans

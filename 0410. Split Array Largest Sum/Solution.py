from typing import List


class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def valid(nums: List[int], m: int, sum_limit: int) -> bool:
            accum, cnt = 0, 1
            for e in nums:
                accum += e
                if accum > sum_limit:
                    accum = e
                    cnt += 1
            return cnt <= m

        left, right = max(nums), sum(nums)
        while left < right:
            mid = left + ((right - left) >> 1)
            if valid(nums, m, mid):
                right = mid
            else:
                left = mid + 1
        return left

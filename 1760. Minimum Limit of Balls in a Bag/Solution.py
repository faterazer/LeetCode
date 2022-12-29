from typing import List


class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        left, right = 1, max(nums)
        while left < right:
            mid = left + (right - left) // 2
            cnt = sum((e - 1) // mid for e in nums)
            if cnt > maxOperations:
                left = mid + 1
            else:
                right = mid
        return left

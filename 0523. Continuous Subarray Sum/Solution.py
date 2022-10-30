from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        pre_sum, idx_map = 0, {0: -1}
        for i, e in enumerate(nums):
            pre_sum += e
            remainder = pre_sum % k
            if remainder in idx_map and i - idx_map[remainder] > 1:
                return True
            elif remainder not in idx_map:
                idx_map[remainder] = i
        return False

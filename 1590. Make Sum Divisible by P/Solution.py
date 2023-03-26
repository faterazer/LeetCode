from typing import List


class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total = sum(nums) % p
        if total == 0:
            return 0

        memo = {0: -1}
        res, pre_sum = len(nums), 0
        for i, x in enumerate(nums):
            pre_sum = (pre_sum + x) % p
            memo[pre_sum] = i
            need = (pre_sum - total) % p
            if need in memo:
                res = min(res, i - memo[need])
        return res if res < len(nums) else -1

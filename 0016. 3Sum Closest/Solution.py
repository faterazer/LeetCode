from math import inf
from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n, res, min_diff = len(nums), 0, inf
        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            s = nums[i] + nums[i + 1] + nums[i + 2]
            if s > target:
                if s - target < min_diff:
                    return s

            s = nums[i] + nums[n - 2] + nums[n - 1]
            if s < target:
                if target - s < min_diff:
                    min_diff = target - s
                    res = s

            j, k = i + 1, n - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s == target:
                    return s
                elif s < target:
                    if target - s < min_diff:
                        min_diff = target - s
                        res = s
                    j += 1
                else:
                    if s - target < min_diff:
                        min_diff = s - target
                        res = s
                    k -= 1

        return res

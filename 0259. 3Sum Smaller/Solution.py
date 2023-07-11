from typing import List


class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        nums.sort()
        res, n = 0, len(nums)
        for i in range(n):
            j, k = i + 1, n - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s < target:
                    res += k - j
                    j += 1
                else:
                    k -= 1
        return res

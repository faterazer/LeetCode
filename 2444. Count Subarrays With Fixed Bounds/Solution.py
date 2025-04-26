class Solution:
    def countSubarrays(self, nums: list[int], minK: int, maxK: int) -> int:
        ans = 0
        beg = min_i = max_i = -1
        for i, x in enumerate(nums):
            if x == minK:
                min_i = i
            if x == maxK:
                max_i = i
            if x < minK or x > maxK:
                beg = i
            ans += max(0, min(min_i, max_i) - beg)
        return ans

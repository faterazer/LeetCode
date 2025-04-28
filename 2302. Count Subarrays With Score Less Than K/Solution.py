class Solution:
    def countSubarrays(self, nums: list[int], k: int) -> int:
        i = s = ans = 0
        for j, x in enumerate(nums):
            s += x
            while s * (j - i + 1) >= k:
                s -= nums[i]
                i += 1
            ans += j - i + 1
        return ans

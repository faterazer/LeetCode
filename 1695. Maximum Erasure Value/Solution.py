class Solution:
    def maximumUniqueSubarray(self, nums: list[int]) -> int:
        seen = set()
        s = ans = i = 0
        for x in nums:
            while x in seen:
                seen.remove(nums[i])
                s -= nums[i]
                i += 1
            s += x
            seen.add(x)
            ans = max(ans, s)
        return ans

class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        ans = cnt = mx = 0
        for x in nums:
            if x > mx:
                ans = cnt = 1
                mx = x
            elif x == mx:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 0
        return ans

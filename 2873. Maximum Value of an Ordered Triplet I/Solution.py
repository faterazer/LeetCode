class Solution:
    def maximumTripletValue(self, nums: list[int]) -> int:
        ans = max_margin = mx = 0
        for x in nums:
            ans = max(ans, max_margin * x)
            max_margin = max(max_margin, mx - x)
            mx = max(mx, x)
        return ans

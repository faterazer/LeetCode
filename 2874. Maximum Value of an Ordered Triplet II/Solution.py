class Solution:
    def maximumTripletValue(self, nums: list[int]) -> int:
        ans = mx = max_margin = 0
        for x in nums:
            ans = max(ans, max_margin * x)
            max_margin = max(max_margin, mx - x)
            mx = max(mx, x)
        return ans

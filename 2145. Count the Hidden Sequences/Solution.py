class Solution:
    def numberOfArrays(self, differences: list[int], lower: int, upper: int) -> int:
        mn = mx = x = 0
        for d in differences:
            x += d
            mn, mx = min(mn, x), max(mx, x)
        return max(upper - mx + mn - lower + 1, 0)

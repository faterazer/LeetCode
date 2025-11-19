class Solution:
    def findFinalValue(self, nums: list[int], original: int) -> int:
        mask = 0
        for x in nums:
            k, r = divmod(x, original)
            if r == 0 and (k & (k - 1)) == 0:
                mask |= k
        mask = ~mask
        return original * (mask & -mask)

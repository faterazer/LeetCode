class Solution:
    def maximumOr(self, nums: list[int], k: int) -> int:
        all_or = fixed = 0
        for x in nums:
            fixed |= all_or & x
            all_or |= x
        return max((all_or ^ x) | fixed | (x << k) for x in nums)

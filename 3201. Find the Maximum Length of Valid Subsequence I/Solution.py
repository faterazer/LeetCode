class Solution:
    def maximumLength(self, nums: list[int]) -> int:
        a, b, c, i = 0, 0, 1, 0
        for j, x in enumerate(nums):
            if x & 1:
                a += 1
            else:
                b += 1
            if (nums[i] & 1) != (x & 1):
                c += 1
                i = j
        return max(a, b, c)

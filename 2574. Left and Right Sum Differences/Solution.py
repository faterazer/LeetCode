class Solution:
    def leftRightDifference(self, nums: list[int]) -> list[int]:
        lsum, rsum = 0, sum(nums)
        result = [0] * len(nums)
        for i, x in enumerate(nums):
            rsum -= x
            result[i] = abs(lsum - rsum)
            lsum += x
        return result

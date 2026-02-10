class Solution:
    def longestBalanced(self, nums: list[int]) -> int:
        result, n = 0, len(nums)
        odd, even = set(), set()
        for i in range(n):
            odd.clear()
            even.clear()
            for j in range(i, n):
                if nums[j] & 1:
                    odd.add(nums[j])
                else:
                    even.add(nums[j])
                if len(odd) == len(even):
                    result = max(result, j - i + 1)
        return result

class Solution:
    def findKDistantIndices(self, nums: list[int], key: int, k: int) -> list[int]:
        ans = []
        j = 0
        for i, x in enumerate(nums):
            if x != key:
                continue
            j = max(j, i - k)
            while j < len(nums) and j <= i + k:
                ans.append(j)
                j += 1
        return ans

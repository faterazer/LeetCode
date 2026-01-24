class Solution:
    def centeredSubarrays(self, nums: list[int]) -> int:
        n = len(nums)
        result = 0
        for i in range(n):
            seen = set()
            s = 0
            for j in range(i, n):
                seen.add(nums[j])
                s += nums[j]
                if s in seen:
                    result += 1
        return result

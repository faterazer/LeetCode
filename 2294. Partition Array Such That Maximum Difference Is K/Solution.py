class Solution:
    def partitionArray(self, nums: list[int], k: int) -> int:
        nums.sort()
        ans, last = 1, nums[0]
        for x in nums:
            if x - last > k:
                ans += 1
                last = x
        return ans

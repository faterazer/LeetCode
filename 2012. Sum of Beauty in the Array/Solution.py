class Solution:
    def sumOfBeauties(self, nums: list[int]) -> int:
        n = len(nums)
        suf_min = [0] * n
        suf_min[-1] = nums[-1]
        for i in range(n - 2, 1, -1):
            suf_min[i] = min(suf_min[i + 1], nums[i])

        ans, pre_max = 0, nums[0]
        for i in range(1, n - 1):
            if pre_max < nums[i] < suf_min[i + 1]:
                ans += 2
            elif nums[i - 1] < nums[i] < nums[i + 1]:
                ans += 1
            pre_max = max(pre_max, nums[i])
        return ans

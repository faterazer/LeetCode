class Solution:
    def maxIncreasingSubarrays(self, nums: list[int]) -> int:
        ans, pre_cnt, cnt = 1, 0, 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                cnt += 1
            else:
                pre_cnt = cnt
                cnt = 1
            ans = max(ans, cnt // 2, min(pre_cnt, cnt))
        return ans

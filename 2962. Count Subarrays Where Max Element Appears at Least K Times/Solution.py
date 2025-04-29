class Solution:
    def countSubarrays(self, nums: list[int], k: int) -> int:
        mx = max(nums)
        mx_cnt = left = ans = 0
        for x in nums:
            mx_cnt += x == mx
            while mx_cnt == k:
                mx_cnt -= nums[left] == mx
                left += 1
            ans += left
        return ans

class Solution:
    def countValidSelections(self, nums: list[int]) -> int:
        pre_sum = ans = 0
        total = sum(nums)
        for x in nums:
            if x:
                pre_sum += x
            else:
                ans += max(0, 2 - abs(total - 2 * pre_sum))
        return ans

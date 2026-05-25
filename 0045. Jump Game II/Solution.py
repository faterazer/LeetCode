class Solution:
    def jump(self, nums: list[int]) -> int:
        result = cur_end = next_end = 0
        for i in range(len(nums) - 1):
            next_end = max(next_end, i + nums[i])
            if i == cur_end:
                cur_end = next_end
                result += 1
        return result

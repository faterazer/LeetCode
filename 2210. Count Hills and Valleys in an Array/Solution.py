from itertools import pairwise


class Solution:
    def countHillValley(self, nums: list[int]) -> int:
        ans = pre_state = 0
        for x, y in pairwise(nums):
            if x == y:
                continue
            cur_state = (x > y) - (x < y)
            if pre_state == -cur_state:
                ans += 1
            pre_state = cur_state
        return ans

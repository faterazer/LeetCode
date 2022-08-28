from typing import List


class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        dp1 = dp2 = dp3 = 0
        i = 0
        while i < len(nums):
            beg = i
            while i < len(nums) and nums[i] == nums[beg]:
                i += 1
            cnt = i - beg
            if beg > 0 and nums[beg] != nums[beg - 1] + 1:
                if dp1 + dp2 > 0:
                    return False
                dp1 = cnt
                dp2 = dp3 = 0
            else:
                if dp1 + dp2 > cnt:
                    return False
                remain = cnt - dp1 - dp2
                tmp = min(remain, dp3)
                dp3 = tmp + dp2
                dp2 = dp1
                dp1 = remain - tmp
        return dp1 == 0 and dp2 == 0

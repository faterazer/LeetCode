from typing import List


class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [-1] * n
        stk1, stk2 = [], []
        for i, x in enumerate(nums):
            while stk2 and nums[stk2[-1]] < x:
                res[stk2.pop()] = x

            j = len(stk1)
            while j and nums[stk1[j - 1]] < x:
                j -= 1
            stk2.extend(stk1[j:])
            del stk1[j:]
            stk1.append(i)
        return res

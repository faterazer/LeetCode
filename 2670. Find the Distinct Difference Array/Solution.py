from typing import List


class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        st = set()
        for i in range(n):
            st.add(nums[i])
            res[i] = len(st)
        st.clear()
        for i in range(n - 1, -1, -1):
            res[i] -= len(st)
            st.add(nums[i])
        return res

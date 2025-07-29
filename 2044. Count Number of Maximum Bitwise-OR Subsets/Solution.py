from functools import reduce
from operator import or_


class Solution:
    def countMaxOrSubsets(self, nums: list[int]) -> int:
        max_or = reduce(or_, nums)
        n = len(nums)
        ans = 0

        def dfs(i: int, cur_or: int) -> None:
            if cur_or == max_or:
                nonlocal ans
                ans += 1 << (n - i)
                return
            if i == n:
                return
            dfs(i + 1, cur_or)
            dfs(i + 1, cur_or | nums[i])

        dfs(0, 0)
        return ans

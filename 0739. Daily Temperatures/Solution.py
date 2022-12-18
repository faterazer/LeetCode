from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        stack = []
        res = [0] * n
        for i, e in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < e:
                idx = stack.pop()
                res[idx] = i - idx
            stack.append(i)
        return res

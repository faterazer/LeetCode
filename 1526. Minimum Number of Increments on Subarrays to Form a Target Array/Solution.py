from itertools import pairwise


class Solution:
    def minNumberOperations(self, target: list[int]) -> int:
        return target[0] + sum(max(b - a, 0) for a, b in pairwise(target))

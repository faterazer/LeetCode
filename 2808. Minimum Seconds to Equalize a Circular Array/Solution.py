import itertools
from collections import defaultdict
from typing import List


class Solution:
    def minimumSeconds(self, nums: List[int]) -> int:
        ids_map = defaultdict(list)
        for i, e in enumerate(nums):
            ids_map[e].append(i)

        res = n = len(nums)
        for ids in ids_map.values():
            ids.append(n + ids[0])
            max_gap = max(j - i for i, j in itertools.pairwise(ids))
            res = min(res, max_gap)
        return res // 2

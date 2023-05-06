from itertools import pairwise
from typing import List


class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        res, max_t = logs[0]
        for (_, t1), (i, t2) in pairwise(logs):
            span = t2 - t1
            if span > max_t or (span == max_t and res > i):
                res, max_t = i, span
        return res

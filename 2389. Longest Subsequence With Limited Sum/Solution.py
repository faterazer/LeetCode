from bisect import bisect_right
from itertools import accumulate
from typing import List


class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        A = list(accumulate(sorted(nums)))
        return [bisect_right(A, query) for query in queries]

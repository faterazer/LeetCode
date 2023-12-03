from itertools import accumulate
from typing import List


class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        diff = [0] * 1001
        for num, i, j in trips:
            diff[i] += num
            diff[j] -= num
        return all(accum <= capacity for accum in accumulate(diff))

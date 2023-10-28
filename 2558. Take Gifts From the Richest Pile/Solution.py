import heapq
import math
from typing import List


class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        for i, e in enumerate(gifts):
            gifts[i] = -e

        heapq.heapify(gifts)
        while k and -gifts[0] > 1:
            heapq.heapreplace(gifts, -math.isqrt(-gifts[0]))
            k -= 1
        return -sum(gifts)

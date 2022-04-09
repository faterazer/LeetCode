import heapq
from collections import Counter
from typing import Counter, List


class Solution:
    def topKFrequent_MK1(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        heap = []
        for key, value in cnt.items():
            heapq.heappush(heap, (value, key))
            if len(heap) > k:
                heapq.heappop(heap)
        return [e[1] for e in heap]

    def topKFrequent_MK2(self, nums: List[int], k: int) -> List[int]:
        return [e[0] for e in Counter(nums).most_common(k)]

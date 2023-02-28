from collections import defaultdict
from itertools import chain
from typing import List


class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        c = defaultdict(int)
        for v, w in chain(items1, items2):
            c[v] += w
        return sorted([k, v] for k, v in c.items())

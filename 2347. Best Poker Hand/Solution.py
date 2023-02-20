from collections import Counter
from typing import List


class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if max(suits) == min(suits):
            return "Flush"
        c = Counter(ranks)
        if len(c) == 5:
            return "High Card"
        for v in c.values():
            if v > 2:
                return "Three of a Kind"
        return "Pair"

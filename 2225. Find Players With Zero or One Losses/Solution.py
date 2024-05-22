from collections import Counter
from typing import List


class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        player = set(x for m in matches for x in m)
        loss_cnt = Counter(loser for _, loser in matches)
        return [sorted(x for x in player if x not in loss_cnt), sorted(x for x, c in loss_cnt.items() if c == 1)]

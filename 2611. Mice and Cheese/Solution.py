from heapq import nlargest
from typing import List


class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        return sum(reward2) + sum(nlargest(k, (a - b for a, b in zip(reward1, reward2))))
        
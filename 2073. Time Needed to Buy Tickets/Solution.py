from typing import List


class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        return sum(min(e, tickets[k]) for e in tickets[: k + 1]) + sum(min(e, tickets[k] - 1) for e in tickets[k + 1 :])

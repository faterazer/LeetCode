from collections import defaultdict
from typing import List


class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        n = len(votes[0])
        cnt = defaultdict(lambda: [0] * n)
        for vote in votes:
            for i, c in enumerate(vote):
                cnt[c][i] -= 1
        return "".join(sorted(cnt, key=lambda x: (cnt[x], x)))

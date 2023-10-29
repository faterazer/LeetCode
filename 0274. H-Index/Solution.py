from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        cnt = [0] * (n + 1)
        for c in citations:
            cnt[min(c, n)] += 1

        res = 0
        for i in range(n, -1, -1):
            res += cnt[i]
            if res >= i:
                return i
        return 0

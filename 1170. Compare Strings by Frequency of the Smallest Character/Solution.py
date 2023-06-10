from typing import List


class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        def f(s: str) -> int:
            return s.count(min(s))

        cnt = [0] * 12
        for w in words:
            cnt[f(w)] += 1
        for i in range(9, 0, -1):
            cnt[i] += cnt[i + 1]
        return [cnt[f(q) + 1] for q in queries]

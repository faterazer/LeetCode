from collections import Counter


class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt = sorted(Counter(word).values(), reverse=True)
        return sum(e * (i // 8 + 1) for i, e in enumerate(cnt))

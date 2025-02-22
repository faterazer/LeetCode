from collections import defaultdict


class Solution:
    def similarPairs(self, words: list[str]) -> int:
        cnt = defaultdict(int)
        ans = 0
        for word in words:
            key = 0
            for c in word:
                key |= 1 << (ord(c) - ord("a"))
            ans += cnt[key]
            cnt[key] += 1
        return ans

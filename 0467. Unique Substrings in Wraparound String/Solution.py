from collections import defaultdict


class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        cnt = defaultdict(int)
        span = 0
        for i, c in enumerate(p):
            if i and (ord(c) - ord(p[i - 1]) + 26) % 26 == 1:
                span += 1
            else:
                span = 1
            cnt[c] = max(cnt[c], span)
        return sum(cnt.values())

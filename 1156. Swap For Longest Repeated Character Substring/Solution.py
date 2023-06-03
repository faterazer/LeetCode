from collections import Counter
from itertools import groupby


class Solution:
    def maxRepOpt1(self, text: str) -> int:
        cnt = Counter(text)
        groups = [(c, len(list(g))) for c, g in groupby(text)]
        res = max(min(v + 1, cnt[k]) for k, v in groups)
        for a, b, c in zip(groups, groups[1:], groups[2:]):
            if a[0] == c[0] and b[1] == 1:
                res = max(res, min(a[1] + c[1] + 1, cnt[a[0]]))
        return res

from collections import defaultdict
from functools import reduce
from typing import List


class Solution:
    def maxProduct(self, words: List[str]) -> int:
        cnt = defaultdict(int)
        for word in words:
            x = reduce(lambda a, b: a | (1 << (ord(b) - ord("a"))), word, 0)
            cnt[x] = max(cnt[x], len(word))
        res = 0
        for k1, v1 in cnt.items():
            for k2, v2 in cnt.items():
                if (k1 & k2) == 0:
                    res = max(res, v1 * v2)
        return res

from collections import Counter
from itertools import permutations
from typing import List


class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        cnt = Counter(s)
        if sum(v % 2 for v in cnt.values()) > 1:
            return []

        buff, odd = [], ""
        for k, v in cnt.items():
            buff.extend(k * (v // 2))
            if v % 2 == 1:
                odd = k
        res = []
        for p in set(permutations("".join(buff))):
            prefix = "".join(p)
            res.append(prefix + odd + prefix[::-1])
        return res

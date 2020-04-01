from typing import List


class Solution:
    def maxDepthAfterSplit_MK1(self, seq: str) -> List[int]:
        ret = []
        d = 0
        for ch in seq:
            if ch == '(':
                ret.append(d % 2)
                d += 1
            else:
                d -= 1
                ret.append(d % 2)
        return ret

    def maxDepthAfterSplit_MK2(self, seq: str) -> List[int]:
        return [i & 1 ^ (c == '(') for i, c in enumerate(seq)]

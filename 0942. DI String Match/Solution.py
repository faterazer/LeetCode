from typing import List


class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        l, r, i = 0, len(S), 0
        ret = [0] * (r + 1)
        for ch in S:
            if ch == 'I':
                ret[i] = l
                l += 1
            else:
                ret[i] = r
                r -= 1
            i += 1
        ret[i] = l
        return ret

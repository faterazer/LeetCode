from typing import List


class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        ret = []
        n = 0
        for x in A:
            n = (n * 2 + x) % 5
            ret.append(n == 0)
        return ret

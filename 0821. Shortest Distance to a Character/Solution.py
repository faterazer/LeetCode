from typing import List


class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        res = [0] * len(S)
        lastC = S.find(C)
        for i in range(lastC):
            res[i] = lastC - i
        cur = S.find(C, lastC + 1)
        while cur != -1:
            for i in range(lastC, cur):
                res[i] = min(i - lastC, cur - i)
            lastC = cur
            cur = S.find(C, lastC + 1)
        for i in range(lastC, len(S)):
            res[i] = i - lastC
        return res

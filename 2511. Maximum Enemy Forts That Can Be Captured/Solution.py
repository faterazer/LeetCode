from typing import List


class Solution:
    def captureForts(self, forts: List[int]) -> int:
        pre, res = -1, 0
        for i, e in enumerate(forts):
            if e != 0:
                if pre > -1 and e != forts[pre]:
                    res = max(res, i - pre - 1)
                pre = i
        return res

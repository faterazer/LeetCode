from typing import List


class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        i, x = 0, 1
        res = []
        while i < len(target):
            res.append('Push')
            if x != target[i]:
                res.append('Pop')
            else:
                i += 1
            x += 1
        return res

from typing import List


class Solution:
    def makeGood(self, s: str) -> str:
        res: List[str] = []
        for c in s:
            if res and res[-1].lower() == c.lower() and res[-1] != c:
                res.pop()
            else:
                res.append(c)
        return ''.join(res)

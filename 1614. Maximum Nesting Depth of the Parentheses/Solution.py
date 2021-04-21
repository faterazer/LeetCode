class Solution:
    def maxDepth(self, s: str) -> int:
        lp = res = 0
        for ch in s:
            if ch == '(':
                lp += 1
                res = max(res, lp)
            elif ch == ')':
                lp -= 1
        return res

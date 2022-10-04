class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        res = l = 0
        for c in s:
            if c == "(":
                l += 1
            elif l > 0:
                l -= 1
            else:
                res += 1
        return res + l

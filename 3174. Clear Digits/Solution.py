class Solution:
    def clearDigits(self, s: str) -> str:
        res = []
        for c in s:
            if c.isdigit():
                res.pop()
            else:
                res.append(c)
        return "".join(res)

class Solution:
    def makeFancyString(self, s: str) -> str:
        res = []
        prev, cnt = s[0], 0
        for c in s:
            if c == prev:
                cnt += 1
            else:
                cnt, prev = 1, c
            if cnt < 3:
                res.append(c)
        return "".join(res)

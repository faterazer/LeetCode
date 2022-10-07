class Solution:
    def numDecodings(self, s: str) -> int:
        a, b = 0, 1
        for i, c in enumerate(s):
            r = 0
            if c != "0":
                r = b
            if i > 0 and s[i - 1] != "0" and int(s[i - 1 : i + 1]) <= 26:
                r += a
            a, b = b, r
        return r

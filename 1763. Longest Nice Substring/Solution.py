class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        st = set(s)
        for i, c in enumerate(s):
            if c.swapcase() not in st:
                left = self.longestNiceSubstring(s[:i])
                right = self.longestNiceSubstring(s[i + 1:])
                return max(left, right, key=len)
        return s

class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        if len(s) < len(t):
            return self.isOneEditDistance(t, s)
        if len(s) - len(t) > 2:
            return False

        i = 0
        while i < len(s) and i < len(t):
            if s[i] != t[i]:
                return s[i + 1 :] == t[i + 1 :] or s[i + 1 :] == t[i:]
            i += 1
        return i == len(s) - 1

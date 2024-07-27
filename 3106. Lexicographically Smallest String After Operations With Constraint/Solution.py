class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        s = list(s)
        for i, c in enumerate(s):
            d = min(ord(c) - ord("a"), ord("z") + 1 - ord(c))
            if d > k:
                s[i] = chr(ord(c) - k)
                break
            s[i] = "a"
            k -= d
        return "".join(s)

class Solution:
    def getSmallestString(self, s: str) -> str:
        sl = list(s)
        for i in range(1, len(sl)):
            a, b = sl[i - 1], s[i]
            if ord(a) % 2 == ord(b) % 2 and b < a:
                sl[i - 1], sl[i] = sl[i], sl[i - 1]
                break
        return "".join(sl)

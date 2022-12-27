class Solution:
    def minimumMoves(self, s: str) -> int:
        i = res = 0
        while i < len(s):
            if s[i] == "O":
                i += 1
            else:
                i += 3
                res += 1
        return res

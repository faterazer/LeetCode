class Solution:
    def repeatedCharacter(self, s: str) -> str:
        seen = 0
        for c in s:
            offset = ord(c) - ord("a")
            if seen & (1 << offset):
                return c
            seen |= 1 << offset

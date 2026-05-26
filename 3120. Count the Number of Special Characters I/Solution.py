class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        seen = [0] * 26
        for c in word:
            if "a" <= c <= "z":
                seen[ord(c) - ord("a")] |= 1
            else:
                seen[ord(c) - ord("A")] |= 2
        return seen.count(3)

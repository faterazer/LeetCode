class Solution:
    def minimumLength(self, s: str) -> int:
        i, j = 0, len(s) - 1
        while i < j and s[i] == s[j]:
            c = s[i]
            while i <= j and s[i] == c:
                i += 1
            while j >= i and s[j] == c:
                j -= 1
        return j - i + 1

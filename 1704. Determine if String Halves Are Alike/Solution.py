class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        n = len(s) // 2
        return sum(c in vowels for c in s[:n]) == sum(c in vowels for c in s[n:])

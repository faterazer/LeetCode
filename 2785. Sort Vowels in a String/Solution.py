class Solution:
    def sortVowels(self, s: str) -> str:
        isVowel = lambda c: c in "aeiouAEIOU"

        vowels = sorted(filter(isVowel, s))
        t = list(s)
        j = 0
        for i, c in enumerate(t):
            if isVowel(c):
                t[i] = vowels[j]
                j += 1
        return "".join(t)

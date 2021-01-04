class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        i, j = 0, len(S) - 1
        s = list(S)
        while i < j:
            while i < j and not S[i].isalpha():
                i += 1
            while i < j and not S[j].isalpha():
                j -= 1
            s[i], s[j] = s[j], s[i]
            i, j = i + 1, j - 1
        return ''.join(s)

class Solution:
    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r and s[l] == s[r]:
            l += 1
            r -= 1
        return l >= r or s[l+1:r+1] == s[l+1:r+1][::-1] or s[l:r] == s[l:r][::-1]

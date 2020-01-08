class Solution:
    def titleToNumber(self, s: str) -> int:
        ans = 0
        for ch in s:
            ans = ans * 26 + (ord(ch) - ord('A')) + 1
        return ans
        
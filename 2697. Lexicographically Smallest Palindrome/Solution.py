class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        return "".join(map(min, s, s[::-1]))

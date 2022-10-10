class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) < 2:
            return ""
        for i, c in enumerate(palindrome[: len(palindrome) // 2]):
            if c != "a":
                return palindrome[:i] + "a" + palindrome[i + 1 :]
        return palindrome[:-1] + "b"

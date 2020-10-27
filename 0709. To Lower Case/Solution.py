class Solution:
    def toLowerCase(self, str: str) -> str:
        c = ord('a') - ord('A')
        return ''.join([chr(ord(ch) + c) if 'A' <= ch <= 'Z' else ch for ch in str])

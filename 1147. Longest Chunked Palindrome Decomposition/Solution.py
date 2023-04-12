class Solution:
    def longestDecomposition(self, text: str) -> int:
        if not text:
            return 0
        for i in range(1, len(text) // 2 + 1):
            if text[:i] == text[-i:]:
                return 2 + self.longestDecomposition(text[i:-i])
        return 1

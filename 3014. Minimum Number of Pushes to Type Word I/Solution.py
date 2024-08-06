class Solution:
    def minimumPushes(self, word: str) -> int:
        a, b = divmod(len(word), 8)
        return (1 + a) * (4 * a + b)

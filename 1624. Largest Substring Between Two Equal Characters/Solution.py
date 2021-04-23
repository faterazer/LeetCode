class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        memo = {}
        return max(i - memo.setdefault(c, i+ 1) for i, c in enumerate(s))

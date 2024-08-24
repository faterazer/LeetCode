class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        ch2idx = {c: i for i, c in enumerate(s)}
        return sum(abs(ch2idx[c] - i) for i, c in enumerate(t))

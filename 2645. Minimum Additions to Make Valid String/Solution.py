import itertools


class Solution:
    def addMinimum(self, word: str) -> int:
        groups = 1 + sum(x >= y for x, y in itertools.pairwise(word))
        return 3 * groups - len(word)

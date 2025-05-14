from itertools import groupby


class Solution:
    def getLongestSubsequence(self, words: list[str], groups: list[int]) -> list[str]:
        return [next(g)[0] for _, g in groupby(zip(words, groups), key=lambda x: x[1])]

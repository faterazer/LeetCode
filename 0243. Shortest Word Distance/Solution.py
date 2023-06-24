from typing import List


class Solution:
    def shortestDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        res = n = len(wordsDict)
        idx1 = idx2 = -n
        for i, w in enumerate(wordsDict):
            if word1 == w:
                idx1 = i
                res = min(res, idx1 - idx2)
            elif word2 == w:
                idx2 = i
                res = min(res, idx2 - idx1)
        return res

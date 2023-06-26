from typing import List


class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        res = float("inf")
        idx1 = idx2 = -1
        is_same = word1 == word2
        for i, w in enumerate(wordsDict):
            if w == word1:
                idx1 = i
                if is_same:
                    idx1, idx2 = idx2, idx1
                if idx1 != -1 and idx2 != -1:
                    res = min(res, abs(idx1 - idx2))
            elif w == word2:
                idx2 = i
                if idx1 != -1 and idx2 != -1:
                    res = min(res, abs(idx2 - idx1))
        return res

from typing import List


class WordDistance:
    def __init__(self, wordsDict: List[str]):
        self.s2idxs = {}
        for i, word in enumerate(wordsDict):
            self.s2idxs.setdefault(word, []).append(i)

    def shortest(self, word1: str, word2: str) -> int:
        arr1, arr2 = self.s2idxs[word1], self.s2idxs[word2]
        m, n = len(arr1), len(arr2)
        i = j = 0
        res = float("inf")
        while i < m and j < n:
            if arr1[i] < arr2[j]:
                res = min(res, arr2[j] - arr1[i])
                i += 1
            else:
                res = min(res, arr1[i] - arr2[j])
                j += 1
        return res


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(wordsDict)
# param_1 = obj.shortest(word1,word2)

from typing import List


class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        res = []
        for word in words:
            if all(word.find(a) == pattern.find(b) for a, b in zip(word, pattern)):
                res.append(word)
        return res

import collections
from typing import List


class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        c = collections.Counter(filter(str.isalpha, licensePlate.lower()))
        res = 'a' * 16
        for word in words:
            if len(word) >= len(res):
                continue
            if c == c & collections.Counter(word):
                res = word
        return res

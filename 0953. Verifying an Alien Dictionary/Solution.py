from typing import List


class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        dict = {c: i for i, c in enumerate(order)}
        return words == sorted(words, key=lambda w: [dict[x] for x in w])

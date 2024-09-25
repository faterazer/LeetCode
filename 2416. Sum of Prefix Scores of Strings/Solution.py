from collections import defaultdict
from typing import List


class Node:
    __slots__ = ("children", "score")

    def __init__(self) -> None:
        self.children = defaultdict(Node)
        self.score = 0


class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        root = Node()
        for word in words:
            cur = root
            for c in word:
                cur = cur.children[c]
                cur.score += 1

        ans = [0] * len(words)
        for i, word in enumerate(words):
            cur = root
            for c in word:
                cur = cur.children[c]
                ans[i] += cur.score
        return ans

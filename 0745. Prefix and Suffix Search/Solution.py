from collections import defaultdict
from typing import List


class TrieNode:
    def __init__(self) -> None:
        self.children = defaultdict(lambda: TrieNode())
        self.idxs = set()


class WordFilter:
    def __init__(self, words: List[str]):
        self.front_root = TrieNode()
        self.back_root = TrieNode()
        s2idx = {}
        for i, e in enumerate(words):
            s2idx[e] = i
        for word, idx in s2idx.items():
            cur = self.front_root
            for c in word:
                cur = cur.children[c]
                cur.idxs.add(idx)

            cur = self.back_root
            for c in word[::-1]:
                cur = cur.children[c]
                cur.idxs.add(idx)

    def f(self, pref: str, suff: str) -> int:
        cur = self.front_root
        for c in pref:
            if c not in cur.children:
                return -1
            cur = cur.children[c]
        candidates = cur.idxs
        if not candidates:
            return -1

        cur = self.back_root
        for c in suff[::-1]:
            if c not in cur.children:
                return - 1
            cur = cur.children[c]
        if not (cur.idxs & candidates):
            return -1
        return max(e for e in cur.idxs if e in candidates)


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(pref,suff)

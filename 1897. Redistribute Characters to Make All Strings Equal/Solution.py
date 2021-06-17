import collections
import functools
from typing import List


class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        c = functools.reduce(collections.Counter.__add__, (collections.Counter(w) for w in words))
        return all(v % len(words) == 0 for v in c.values())

from typing import List


class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        res = 0
        seen = set()
        for w in words:
            if w[::-1] in seen:
                res += 1
            seen.add(w)
        return res

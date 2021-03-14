from typing import List


class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        s = ' '.join(words)
        return [w for w in words if s.count(w) > 1]

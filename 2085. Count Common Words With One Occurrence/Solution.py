from collections import Counter
from typing import List


class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        cnt1, cnt2 = Counter(words1), Counter(words2)
        return sum(v == 1 and cnt2[k] == 1 for k, v in cnt1.items())

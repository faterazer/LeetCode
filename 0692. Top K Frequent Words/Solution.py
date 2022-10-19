from collections import Counter
from typing import List


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        return sorted((cnt := Counter(words)).keys(), key=lambda word: (-cnt[word], word))[:k]

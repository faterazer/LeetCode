from collections import Counter


class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        cnt = Counter(word[i : i + k] for i in range(0, len(word), k))
        return len(word) // k - max(cnt.values())

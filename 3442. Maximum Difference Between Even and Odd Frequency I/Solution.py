from collections import Counter


class Solution:
    def maxDifference(self, s: str) -> int:
        cnt = Counter(s)
        max_odd = max(v for v in cnt.values() if (v & 1) == 1)
        min_even = min(v for v in cnt.values() if (v & 1) == 0)
        return max_odd - min_even

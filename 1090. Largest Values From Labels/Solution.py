from collections import Counter
from typing import List


class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], numWanted: int, useLimit: int) -> int:
        cnt = Counter()
        res = c = 0
        for val, label in sorted(zip(values, labels), reverse=True):
            cnt[label] += 1
            if cnt[label] > useLimit:
                continue
            res += val
            if (c := c + 1) == numWanted:
                break
        return res

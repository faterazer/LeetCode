from itertools import accumulate
from typing import List


class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        pre_sum = list(accumulate((w[0] in "aeiou" and w[-1] in "aeiou" for w in words), initial=0))
        return [pre_sum[r + 1] - pre_sum[l] for l, r in queries]

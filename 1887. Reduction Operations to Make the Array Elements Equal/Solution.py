from collections import Counter
from itertools import accumulate
from typing import List


class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        cnt = sorted(Counter(nums).items(), key=lambda x: x[0], reverse=True)
        return sum(accumulate([v for k, v in cnt[:-1]]))

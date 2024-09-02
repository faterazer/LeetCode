import bisect
from itertools import accumulate
from typing import List


class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        return bisect.bisect(list(accumulate(chalk)), k % sum(chalk))

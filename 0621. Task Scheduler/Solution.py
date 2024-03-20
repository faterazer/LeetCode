from collections import Counter
from typing import List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cnt = Counter(tasks)
        max_val = cnt.most_common(1)[0][1]
        max_cnt = sum(v == max_val for v in cnt.values())
        return max(max_val + (max_val - 1) * n - 1 + max_cnt, len(tasks))

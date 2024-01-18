from typing import List


class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        beans.sort()
        return sum(beans) - max(e * (len(beans) - i) for i, e in enumerate(beans))

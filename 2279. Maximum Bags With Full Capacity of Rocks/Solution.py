from typing import List


class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        diff = sorted(a - b for a, b in zip(capacity, rocks))
        res = 0
        for d in diff:
            if additionalRocks < d:
                break
            additionalRocks -= d
            res += 1
        return res

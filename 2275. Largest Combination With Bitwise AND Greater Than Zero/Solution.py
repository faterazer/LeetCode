from typing import List


class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        m = max(candidates).bit_length()
        return max(sum(x >> i & 1 for x in candidates) for i in range(m))

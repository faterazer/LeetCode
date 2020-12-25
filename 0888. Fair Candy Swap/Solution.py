from typing import List


class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        diff = (sum(A) - sum(B)) // 2
        setB = set(B)
        for x in A:
            if x - diff in setB:
                return [x, x - diff]
        return []

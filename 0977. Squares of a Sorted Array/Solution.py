from typing import List


class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        ret = [0] * len(A)
        l, r, n = 0, len(A) - 1, len(ret) - 1
        while l <= r:
            if abs(A[l]) > abs(A[r]):
                ret[n] = A[l] * A[l]
                l += 1
            else:
                ret[n] = A[r] * A[r]
                r -= 1
            n -= 1
        return ret

from typing import List


class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        accum = sum(x for x in A if x % 2 == 0)
        ret = []
        for val, idx in queries:
            if A[idx] % 2 == 0:
                accum -= A[idx]
            A[idx] += val
            if A[idx] % 2 == 0:
                accum += A[idx]
            ret.append(accum)
        return ret

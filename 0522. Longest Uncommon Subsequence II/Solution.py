from typing import List


class Solution:
    def findLUSlength(self, strs: List[str]) -> int:

        def isSubseq(A: str, B: str) -> bool:
            # Return true if B is a subsequence of A
            ai = bi = 0
            while ai < len(A) and bi < len(B):
                if A[ai] == B[bi]:
                    bi += 1
                ai += 1
            return bi == len(B)

        strs.sort(key=len, reverse=True)
        for i, a in enumerate(strs):
            if all(not isSubseq(b, a) for j, b in enumerate(strs) if i != j):
                return len(a)
        return -1

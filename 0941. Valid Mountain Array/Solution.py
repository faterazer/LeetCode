from typing import List


class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        i, j = 0, len(A) - 1
        while i < j and A[i] < A[i + 1]:
            i += 1
        while i < j and A[j] < A[j - 1]:
            j -= 1
        return 0 < i == j < len(A) - 1

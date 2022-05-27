import random
from typing import List


class Solution:
    def repeatedNTimes_MK1(self, A: List[int]) -> int:
        for i in range(2, len(A)):
            if A[i] == A[i - 1] or A[i] == A[i - 2]:
                return A[i]
        return A[0]

    def repeatedNTimes_MK2(self, A: List[int]) -> int:
        n = len(A)
        for _ in range(10):
            x, y = random.randrange(n), random.randrange(n)
            if x != y and A[x] == A[y]:
                return A[x]
        return self.repeatedNTimes_MK1(A)

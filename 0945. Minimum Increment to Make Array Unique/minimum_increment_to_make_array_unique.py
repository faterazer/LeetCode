from typing import List


class Solution:
    def minIncrementForUnique_MK1(self, A: List[int]) -> int:
        A.sort()
        ret = 0
        for i in range(1, len(A)):
            if A[i] <= A[i - 1]:
                ret += A[i - 1] + 1 - A[i]
                A[i] = A[i - 1] + 1
        return ret

    def minIncrementForUnique_MK2(self, A: List[int]) -> int:
        buff = [0] * 80001
        for n in A:
            buff[n] += 1
        ret, size = 0, len(A)
        for i in range(len(buff) - 1):
            if buff[i] == 1:
                size -= 1
            elif buff[i] > 1:
                buff[i + 1] += buff[i] - 1
                ret += buff[i] - 1
                size -= 1
            if not size:
                break
        return ret

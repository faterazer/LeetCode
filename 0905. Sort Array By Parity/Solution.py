from typing import List


class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        front, rear = 0, len(A) - 1
        while front < rear:
            if A[front] % 2:
                A[front], A[rear] = A[rear], A[front]
                rear -= 1
            else:
                front += 1
        return A

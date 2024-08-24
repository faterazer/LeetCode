from typing import List


MOD = 10**9 + 7


def matmul(A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
    return [[sum(x * y for x, y in zip(row, col)) % MOD for col in zip(*B)] for row in A]


def pow(a: List[List[int]], n: int) -> List[List[int]]:
    size = len(a)
    res = [[0] * size for _ in range(size)]
    for i in range(size):
        res[i][i] = 1
    while n:
        if n & 1:
            res = matmul(res, a)
        a = matmul(a, a)
        n >>= 1
    return res


class Solution:
    def checkRecord(self, n: int) -> int:
        M = [[1, 1, 0, 1, 0, 0], [1, 0, 1, 1, 0, 0], [1, 0, 0, 1, 0, 0], [0, 0, 0, 1, 1, 0], [0, 0, 0, 1, 0, 1], [0, 0, 0, 1, 0, 0]]
        return sum(pow(M, n)[0]) % MOD

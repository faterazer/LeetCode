from typing import List


class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        buff = [0] * (N + 1)
        for i, j in trust:
            buff[i] -= 1
            buff[j] += 1
        for i in range(1, len(buff)):
            if buff[i] == N - 1:
                return i
        return -1

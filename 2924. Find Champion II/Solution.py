from typing import List


class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        degree = [0] * n
        for _, b in edges:
            degree[b] += 1

        res = -1
        for i, d in enumerate(degree):
            if d == 0:
                if res != -1:
                    return -1
                res = i
        return res

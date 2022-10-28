from collections import Counter
from typing import List


class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        A = [(i, j) for i in range(n) for j in range(n) if img1[i][j]]
        B = [(i, j) for i in range(n) for j in range(n) if img2[i][j]]
        cnt = Counter((xa - xb, ya - yb) for xa, ya in A for xb, yb in B)
        return max(cnt.values() or [0])

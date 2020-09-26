from typing import List, Tuple


class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        m, n = len(M), len(M[0])

        def neighbor(i: int, j: int) -> Tuple[int]:
            dirs = ((-1, 1), (0, 1), (1, 1), (-1, 0), (1, 0), (-1, -1), (0, -1), (1, -1))
            for d in dirs:
                ni, nj = i + d[0], j + d[1]
                if 0 <= ni < m and 0 <= nj < n:
                    yield (ni, nj)
        
        for i in range(m):
            for j in range(n):
                total, cnt = M[i][j], 1
                for ni, nj in neighbor(i, j):
                    total += M[ni][nj] & 0xFF
                    cnt += 1
                M[i][j] |= (total // cnt) << 8
        
        for i in range(m):
            for j in range(n):
                M[i][j] >>= 8
        return M

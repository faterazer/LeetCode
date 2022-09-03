from typing import List


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        pacific = [[False] * n for _ in range(m)]
        atlantic = [[False] * n for _ in range(m)]

        def dfs(heights: List[List[int]], r: int, c: int, visited: List[List[int]]) -> None:
            m, n = len(heights), len(heights[0])
            if r < 0 or r >= m or c < 0 or c >= n or visited[r][c]:
                return
            visited[r][c] = True
            if r > 0 and heights[r][c] <= heights[r - 1][c]:
                dfs(heights, r - 1, c, visited)
            if r < m - 1 and heights[r][c] <= heights[r + 1][c]:
                dfs(heights, r + 1, c, visited)
            if c > 0 and heights[r][c] <= heights[r][c - 1]:
                dfs(heights, r, c - 1, visited)
            if c < n - 1 and heights[r][c] <= heights[r][c + 1]:
                dfs(heights, r, c + 1, visited)

        for i in range(m):
            dfs(heights, i, 0, pacific)
            dfs(heights, i, n - 1, atlantic)
        for i in range(n):
            dfs(heights, 0, i, pacific)
            dfs(heights, m - 1, i, atlantic)

        return [[i, j] for i in range(m) for j in range(n) if pacific[i][j] and atlantic[i][j]]

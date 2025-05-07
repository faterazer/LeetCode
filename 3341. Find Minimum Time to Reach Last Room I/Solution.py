import heapq


class Solution:
    def minTimeToReach(self, moveTime: list[list[int]]) -> int:
        m, n = len(moveTime), len(moveTime[0])
        pq = [(0, 0, 0)]
        visited = [[False] * n for _ in range(m)]
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        while pq:
            cur_time, r, c = heapq.heappop(pq)
            if r == m - 1 and c == n - 1:
                return cur_time

            if visited[r][c]:
                continue
            visited[r][c] = True

            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc]:
                    nt = max(cur_time, moveTime[nr][nc]) + 1
                    if nr == m - 1 and nc == n - 1:
                        return nt
                    else:
                        heapq.heappush(pq, (nt, nr, nc))
        return -1

from math import inf


class Solution:
    def minimumCost(self, source: str, target: str, original: list[str], changed: list[str], cost: list[int]) -> int:
        dist = [[inf] * 26 for _ in range(26)]
        for i in range(26):
            dist[i][i] = 0
        for x, y, c in zip(original, changed, cost):
            x = ord(x) - ord("a")
            y = ord(y) - ord("a")
            dist[x][y] = min(dist[x][y], c)
        for k in range(26):
            for i in range(26):
                if dist[i][k] == inf:
                    continue
                for j in range(26):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        result = 0
        for x, y in zip(source, target):
            d = dist[ord(x) - ord("a")][ord(y) - ord("a")]
            if d == inf:
                return -1
            result += d
        return result

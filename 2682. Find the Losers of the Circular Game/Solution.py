from typing import List


class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        visited = [False] * n
        i, d = 0, k
        while not visited[i]:
            visited[i] = True
            i = (i + d) % n
            d += k
        return [i for i, e in enumerate(visited, 1) if not e]

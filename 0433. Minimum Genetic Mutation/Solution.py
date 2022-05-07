from collections import deque
from typing import List


class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        def isMutation(old_s: str, new_s: str) -> bool:
            return sum(a != b for a, b in zip(old_s, new_s)) == 1

        visited = [False] * len(bank)
        Q = deque([start])
        cnt = 0
        while Q:
            cnt += 1
            n = len(Q)
            for _ in range(n):
                s = Q.popleft()
                for i, gene in enumerate(bank):
                    if not visited[i] and isMutation(s, gene):
                        if gene == end:
                            return cnt
                        else:
                            visited[i] = True
                            Q.append(gene)
        return -1

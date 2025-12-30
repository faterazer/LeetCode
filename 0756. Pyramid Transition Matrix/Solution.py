from collections import defaultdict


class Solution:
    def pyramidTransition(self, bottom: str, allowed: list[str]) -> bool:
        groups = defaultdict(list)
        for s in allowed:
            groups[s[:2]].append(s[2])
        n = len(bottom)
        pyramid = [[] for i in range(n - 1)] + [list(bottom)]

        seen = set()

        def dfs(i: int, j: int) -> bool:
            if i < 0:
                return True
            row = "".join(pyramid[i])
            if row in seen:
                return False
            if j == i + 1:
                seen.add(row)
                return dfs(i - 1, 0)
            for c in groups[pyramid[i + 1][j] + pyramid[i + 1][j + 1]]:
                pyramid[i].append(c)
                if dfs(i, j + 1):
                    return True
                pyramid[i].pop()
            return False

        return dfs(n - 2, 0)

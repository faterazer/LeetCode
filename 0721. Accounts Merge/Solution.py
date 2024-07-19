from collections import defaultdict
from typing import List


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        email2ids = defaultdict(list)
        for i, account in enumerate(accounts):
            for email in account[1:]:
                email2ids[email].append(i)

        visited = [False] * len(accounts)
        email_set = set()

        def dfs(x: int) -> None:
            visited[x] = True
            for email in accounts[x][1:]:
                if email in email_set:
                    continue
                email_set.add(email)
                for idx in email2ids[email]:
                    if not visited[idx]:
                        dfs(idx)

        res = []
        for i, v in enumerate(visited):
            if not v:
                email_set.clear()
                dfs(i)
                res.append([accounts[i][0]] + sorted(email_set))
        return res

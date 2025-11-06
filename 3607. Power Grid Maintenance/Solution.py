from math import inf


class Solution:
    def processQueries(self, c: int, connections: list[list[int]], queries: list[list[int]]) -> list[int]:
        grid = [[] for _ in range(c + 1)]
        for x, y in connections:
            grid[x].append(y)
            grid[y].append(x)

        node2component = [-1] * (c + 1)
        component_cnt = 0

        def dfs(node: int) -> None:
            node2component[node] = component_cnt
            for neighbor in grid[node]:
                if node2component[neighbor] == -1:
                    dfs(neighbor)

        for i in range(1, c + 1):
            if node2component[i] == -1:
                dfs(i)
                component_cnt += 1

        offline_time = [inf] * (c + 1)
        for i in range(len(queries) - 1, -1, -1):
            type, node = queries[i]
            if type == 2:
                offline_time[node] = i

        mn = [inf] * component_cnt
        for node in range(1, c + 1):
            component = node2component[node]
            if offline_time[node] == inf:
                mn[component] = min(mn[component], node)

        ans = []
        for i in range(len(queries) - 1, -1, -1):
            type, node = queries[i]
            component = node2component[node]
            if type == 2:
                if i == offline_time[node]:
                    mn[component] = min(mn[component], node)
            elif i < offline_time[node]:
                ans.append(node)
            elif mn[component] != inf:
                ans.append(mn[component])
            else:
                ans.append(-1)
        ans.reverse()
        return ans

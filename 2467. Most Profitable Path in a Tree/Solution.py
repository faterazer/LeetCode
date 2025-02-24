class Solution:
    def mostProfitablePath(self, edges: list[list[int]], bob: int, amount: list[int]) -> int:
        n = len(edges) + 1
        tree = [[] for _ in range(n)]
        for x, y in edges:
            tree[x].append(y)
            tree[y].append(x)

        bob_path = [n] * n

        def find_zero(node: int, parent: int, steps: int) -> bool:
            if node == 0:
                bob_path[0] = steps
                return True
            for child in tree[node]:
                if child != parent and find_zero(child, node, steps + 1):
                    bob_path[node] = steps
                    return True
            return False

        find_zero(bob, -1, 0)

        tree[0].append(-1)  # 避免把 0 当作叶子节点

        def dfs(node: int, parent: int, steps: int, profit: int) -> int:
            if bob_path[node] > steps:
                profit += amount[node]
            elif bob_path[node] == steps:
                profit += amount[node] // 2

            if len(tree[node]) == 1:
                return profit

            return max(dfs(child, node, steps + 1, profit) for child in tree[node] if child != -1 and child != parent)

        return dfs(0, -1, 0, 0)

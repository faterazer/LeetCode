# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Node) -> Node:
        if not node:
            return None
        visited = {}

        def dfs(node: Node) -> Node:
            if node in visited:
                return visited[node]
            res = Node(node.val)
            visited[node] = res
            for neighbour in node.neighbors:
                res.neighbors.append(dfs(neighbour))
            return res

        return dfs(node)

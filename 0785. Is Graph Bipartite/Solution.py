from typing import List


class Solution:
    def isBipartite_dfs(self, graph: List[List[int]]) -> bool:
        UNCOLORED, RED, GREEN = 0, 1, 2

        def dfs(graph: List[List[int]], colors: List[int], vertex: int, color: int) -> bool:
            if colors[vertex] != UNCOLORED:
                return colors[vertex] == color
            colors[vertex] = color
            color = GREEN if color == RED else RED
            for neighbor in graph[vertex]:
                if colors[neighbor] == UNCOLORED and not dfs(graph, colors, neighbor, color):
                    return False
                elif colors[neighbor] != color:
                    return False
            return True

        colors = [UNCOLORED] * len(graph)
        for vertex in range(len(graph)):
            if colors[vertex] == UNCOLORED and not dfs(graph, colors, vertex, RED):
                return False
        return True

    def isBipartite(self, graph: List[List[int]]) -> bool:
        UNCOLORED, RED, GREEN = 0, 1, 2
        colors = [UNCOLORED] * len(graph)
        for i in range(len(graph)):
            if colors[i] != UNCOLORED:
                continue
            queue = [i]
            colors[i] = RED
            while queue:
                vertex = queue.pop()
                color = GREEN if colors[vertex] == RED else RED
                for neighbor in graph[vertex]:
                    if colors[neighbor] == UNCOLORED:
                        colors[neighbor] = color
                        queue.append(neighbor)
                    elif colors[neighbor] != color:
                        return False
        return True

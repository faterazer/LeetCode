from collections import defaultdict, deque
from typing import List


class Solution:
    def checkIfPrerequisite(
        self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]
    ) -> List[bool]:
        graph = defaultdict(list)
        in_degrees = [0] * numCourses
        for a, b in prerequisites:
            graph[a].append(b)
            in_degrees[b] += 1

        dep_matrix = [[False] * numCourses for _ in range(numCourses)]
        queue = deque([i for i, degree in enumerate(in_degrees) if degree == 0])
        while queue:
            node = queue.popleft()
            for neighbour in graph[node]:
                dep_matrix[node][neighbour] = True
                for i in range(numCourses):
                    dep_matrix[i][neighbour] |= dep_matrix[i][node]
                in_degrees[neighbour] -= 1
                if in_degrees[neighbour] == 0:
                    queue.append(neighbour)

        return [dep_matrix[a][b] for a, b in queries]

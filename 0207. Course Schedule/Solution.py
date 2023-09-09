from collections import defaultdict, deque
from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjacency_list = defaultdict(list)
        in_degrees = [0] * numCourses

        for a, b in prerequisites:
            adjacency_list[b].append(a)
            in_degrees[a] += 1

        queue = deque([node for node, degree in enumerate(in_degrees) if degree == 0])
        visited = 0
        while queue:
            visited += 1
            node = queue.popleft()
            for neighbour in adjacency_list[node]:
                in_degrees[neighbour] -= 1
                if in_degrees[neighbour] == 0:
                    queue.append(neighbour)
        return visited == numCourses

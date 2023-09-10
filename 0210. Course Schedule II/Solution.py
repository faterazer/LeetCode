from collections import defaultdict, deque
from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adjacency_list = defaultdict(list)
        in_degrees = [0] * numCourses

        for a, b in prerequisites:
            adjacency_list[b].append(a)
            in_degrees[a] += 1

        queue = deque([node for node, degree in enumerate(in_degrees) if degree == 0])
        res = []
        while queue:
            node = queue.popleft()
            res.append(node)
            for neighbour in adjacency_list[node]:
                in_degrees[neighbour] -= 1
                if in_degrees[neighbour] == 0:
                    queue.append(neighbour)
        return res if len(res) == numCourses else []

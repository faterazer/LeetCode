from enum import Enum, unique
from typing import List


@unique
class COLOR(Enum):
    WHITE = -1
    RED = 0
    BLUE = 1


class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        color_map = [COLOR.WHITE] * (n + 1)
        graph = {}
        for a, b in dislikes:
            graph.setdefault(a, []).append(b)
            graph.setdefault(b, []).append(a)

        def dfs(i: int, color: COLOR) -> bool:
            color_map[i] = color
            for neighbour in graph[i]:
                if color_map[neighbour] == color:
                    return False
                if color_map[neighbour] == COLOR.WHITE and not dfs(neighbour, COLOR(1 - color.value)):
                    return False
            return True

        for i in graph.keys():
            if color_map[i] == COLOR.WHITE and not dfs(i, COLOR.BLUE):
                return False
        return True

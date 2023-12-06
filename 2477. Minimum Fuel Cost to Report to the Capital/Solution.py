from collections import defaultdict
from typing import List

class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        graph = defaultdict(list)
        for a, b in roads:
            graph[a].append(b)
            graph[b].append(a)
        
        res = 0
        
        def dfs(node: int, parent: int) -> int:
            size = 1
            for child in graph[node]:
                if child!= parent:
                    size += dfs(child, node)
            if node != 0:
                nonlocal res
                res +=  (size - 1) // seats + 1
            return size
            
        dfs(0, -1)
        return res

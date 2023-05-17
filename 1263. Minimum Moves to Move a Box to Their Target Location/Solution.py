from collections import deque
from typing import List


class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        dirs = ((1, 0), (-1, 0), (0, 1), (0, -1))

        start_state = [0] * 4
        for i, row in enumerate(grid):
            for j, ele in enumerate(row):
                if ele == "B":
                    start_state[0], start_state[1] = i, j
                elif ele == "S":
                    start_state[2], start_state[3] = i, j

        queue = deque([tuple(start_state)])
        seen = set()
        pushes = 0
        while queue:
            next_queue = deque([])
            while queue:
                br, bc, sr, sc = queue.pop()
                if grid[br][bc] == "T":
                    return pushes
                for dr, dc in dirs:
                    nsr, nsc = sr + dr, sc + dc
                    if nsr < 0 or nsr >= m or nsc < 0 or nsc >= n or grid[nsr][nsc] == "#":
                        continue
                    if nsr == br and nsc == bc:
                        nbr, nbc = br + dr, bc + dc
                        if nbr < 0 or nbr >= m or nbc < 0 or nbc >= n or grid[nbr][nbc] == "#":
                            continue
                        next_state = (nbr, nbc, nsr, nsc)
                        seen.add(next_state)
                        next_queue.append(next_state)
                    elif (br, bc, nsr, nsc) not in seen:
                        next_state = (br, bc, nsr, nsc)
                        seen.add(next_state)
                        queue.append(next_state)
            queue = next_queue
            pushes += 1
        return -1

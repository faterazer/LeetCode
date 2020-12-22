from typing import List


class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dirs = ((-1, 0), (0, 1), (1, 0), (0, -1))
        idx = 1     # // index of dirs, represents current direction.
        obs = set(map(tuple, obstacles))
        res = 0
        x, y = 0, 0
        for command in commands:
            if command == -1:
                idx = (idx + 1) % 4
            elif command == -2:
                idx = (idx - 1) % 4
            else:
                for i in range(command):
                    nx, ny = x + dirs[idx][0], y + dirs[idx][1]
                    if (nx, ny) in obs:
                        break
                    x, y = nx, ny
                res = max(res, x ** 2 + y ** 2)
        return res

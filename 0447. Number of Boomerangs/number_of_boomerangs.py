from typing import List


class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        n = len(points)
        ret = 0
        for i in range(n):
            mp = {}
            for j in range(n):
                if i == j:
                    continue
                dist = (points[i][0] - points[j][0]) ** 2 + (points[i][1] - points[j][1]) ** 2
                mp[dist] = mp.get(dist, 0) + 1
                ret += (mp[dist] - 1) * 2
        return ret

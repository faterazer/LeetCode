from typing import List


class Solution:
    def earliestFullBloom_MK1(self, plantTime: List[int], growTime: List[int]) -> int:
        flowers = sorted(zip(plantTime, growTime), key=lambda x: x[1])
        res = 0
        for pt, gt in flowers:
            res = max(res, gt)
            res += pt
        return res

    def earliestFullBloom_MK2(self, plantTime: List[int], growTime: List[int]) -> int:
        flowers = sorted(zip(plantTime, growTime), key=lambda x: x[0], reverse=True)
        res, t = 0, 0
        for pt, gt in flowers:
            res = max(res, t + pt)
            res += gt
        return res

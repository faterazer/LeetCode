from typing import List


class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        def gen(x: int, bound: int) -> int:
            r = 1
            while r < bound:
                yield r
                r *= x

        res = set()
        for i in gen(x, bound):
            for j in gen(y, bound):
                if i + j > bound:
                    break
                else:
                    res.add(i + j)
                if y == 1:
                    break;
            if x == 1:
                break
        return list(res)


from typing import List


class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        lcnt = rcnt = state = 0
        for i, e in enumerate(boxes):
            if e == "1":
                state += i
                rcnt += 1

        res = [0] * len(boxes)
        for i in range(len(res)):
            res[i] = state
            if boxes[i] == "1":
                lcnt -= 1
                rcnt += 1
            state += lcnt - rcnt
        return res

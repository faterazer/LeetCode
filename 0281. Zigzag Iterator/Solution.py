from collections import deque
from typing import List


class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.queue = deque([])
        if v1:
            self.queue.append((0, 0, len(v1)))
        if v2:
            self.queue.append((1, 0, len(v2)))
        self.v = [v1, v2]

    def next(self) -> int:
        idx, cur, end = self.queue.popleft()
        res = self.v[idx][cur]
        if cur + 1 < end:
            self.queue.append((idx, cur + 1, end))
        return res

    def hasNext(self) -> bool:
        return len(self.queue) > 0


# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())

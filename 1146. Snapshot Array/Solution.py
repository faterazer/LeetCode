import bisect
from collections import defaultdict


class SnapshotArray:

    def __init__(self, length: int):
        self.cur_snap_id = 0
        self.history = defaultdict(list)

    def set(self, index: int, val: int) -> None:
        self.history[index].append((self.cur_snap_id, val))

    def snap(self) -> int:
        self.cur_snap_id += 1
        return self.cur_snap_id - 1

    def get(self, index: int, snap_id: int) -> int:
        h = self.history[index]
        i = bisect.bisect_left(h, (snap_id + 1, 0)) - 1
        return h[i][1] if i >= 0 else 0


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)

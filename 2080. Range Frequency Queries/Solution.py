import bisect
from collections import defaultdict


class RangeFreqQuery:

    def __init__(self, arr: list[int]) -> None:
        self.value2ids = defaultdict(list)
        for i, v in enumerate(arr):
            self.value2ids[v].append(i)

    def query(self, left: int, right: int, value: int) -> int:
        return bisect.bisect_right(self.value2ids[value], right) - bisect.bisect_left(self.value2ids[value], left)


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)

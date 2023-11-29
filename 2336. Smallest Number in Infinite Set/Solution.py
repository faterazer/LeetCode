import heapq


class SmallestInfiniteSet:
    def __init__(self):
        self.removed = set()
        self.added = []
        self.bound = 1

    def popSmallest(self) -> int:
        if self.added:
            res = heapq.heappop(self.added)
            self.removed.add(res)
            return res
        else:
            self.removed.add(self.bound)
            self.bound += 1
            return self.bound - 1

    def addBack(self, num: int) -> None:
        if num in self.removed:
            self.removed.remove(num)
            heapq.heappush(self.added, num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)

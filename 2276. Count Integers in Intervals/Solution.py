class CountIntervals:
    __slots__ = "left", "right", "l", "r", "cnt"

    def __init__(self, l: int = 0, r: int = 10**9):
        self.left: CountIntervals = None
        self.right: CountIntervals = None
        self.l, self.r, self.cnt = l, r, 0

    def add(self, left: int, right: int) -> None:
        if self.cnt == self.r - self.l + 1:
            return
        if left <= self.l and self.r <= right:
            self.cnt = self.r - self.l + 1
            return
        m = self.l + (self.r - self.l) // 2
        if self.left is None:
            self.left = CountIntervals(self.l, m)
        if self.right is None:
            self.right = CountIntervals(m + 1, self.r)

        if left <= m:
            self.left.add(left, right)
        if right > m:
            self.right.add(left, right)
        self.cnt = self.left.cnt + self.right.cnt

    def count(self) -> int:
        return self.cnt


# Your CountIntervals object will be instantiated and called as such:
# obj = CountIntervals()
# obj.add(left,right)
# param_2 = obj.count()

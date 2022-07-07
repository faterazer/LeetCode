class MyCalendar:

    def __init__(self):
        self.tree = set()
        self.lazy = set()
        self.len = 10 ** 9

    def query(self, start: int, end: int, l: int, r: int, idx: int) -> bool:
        if r < start or l > end:
            return False
        if idx in self.lazy:
            return True
        if start <= l and r <= end:
            return idx in self.tree
        m = l + ((r - l) >> 1)
        return self.query(start, end, l, m, 2 * idx) or self.query(start, end, m + 1, r, 2 * idx + 1)

    def update(self, start: int, end: int, l: int, r: int, idx: int) -> None:
        if r < start or l > end:
            return
        if start <= l and r <= end:
            self.tree.add(idx)
            self.lazy.add(idx)
        else:
            m = l + ((r - l) >> 1)
            self.update(start, end, l, m, 2 * idx)
            self.update(start, end, m + 1, r, 2 * idx + 1)
            self.tree.add(idx)
            if 2 * idx in self.lazy and 2 * idx + 1 in self.lazy:
                self.lazy.add(idx)

    def book(self, start: int, end: int) -> bool:
        if self.query(start, end - 1, 0, self.len, 1):
            return False
        self.update(start, end - 1, 0, self.len, 1)
        return True

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)

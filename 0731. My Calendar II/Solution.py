class MyCalendarTwo:
    def __init__(self):
        self.tree = {}

    def update(self, start: int, end: int, val: int, idx: int, l: int, r: int) -> None:
        p = self.tree.setdefault(idx, [0, 0])
        if r < start or end < l:
            return

        if start <= l <= r <= end:
            p[0] += val
            p[1] += val
            return
        m = l + ((r - l) >> 1)
        self.update(start, end, val, idx * 2, l, m)
        self.update(start, end, val, idx * 2 + 1, m + 1, r)
        p[0] = p[1] + max(self.tree[idx * 2][0], self.tree[idx * 2 + 1][0])

    def book(self, start: int, end: int) -> bool:
        self.update(start, end - 1, 1, 1, 0, 10**9)
        if self.tree[1][0] > 2:
            self.update(start, end - 1, -1, 1, 0, 10**9)
            return False
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)

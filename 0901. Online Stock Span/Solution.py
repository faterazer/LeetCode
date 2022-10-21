from math import inf


class StockSpanner:
    def __init__(self):
        self.stack = [(inf, 0)]
        self.cnt = 1

    def next(self, price: int) -> int:
        while price >= self.stack[-1][0]:
            self.stack.pop()
        res = self.cnt - self.stack[-1][1]
        self.stack.append((price, self.cnt))
        self.cnt += 1
        return res


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)

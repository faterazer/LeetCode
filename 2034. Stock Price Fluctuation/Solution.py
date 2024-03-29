import heapq


class StockPrice:
    def __init__(self) -> None:
        self.max_heap = []
        self.min_heap = []
        self.records = {}
        self.max_timestamp = 0

    def update(self, timestamp: int, price: int) -> None:
        self.max_timestamp = max(self.max_timestamp, timestamp)
        self.records[timestamp] = price
        heapq.heappush(self.max_heap, (-price, timestamp))
        heapq.heappush(self.min_heap, (price, timestamp))

    def current(self) -> int:
        return self.records[self.max_timestamp]

    def maximum(self) -> int:
        while -self.max_heap[0][0] != self.records[self.max_heap[0][1]]:
            heapq.heappop(self.max_heap)
        return -self.max_heap[0][0]

    def minimum(self) -> int:
        while self.min_heap[0][0] != self.records[self.min_heap[0][1]]:
            heapq.heappop(self.min_heap)
        return self.min_heap[0][0]


# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()

import heapq


class SeatManager:

    def __init__(self, n: int):
        self.seat = 0
        self.available = []

    def reserve(self) -> int:
        if self.available:
            res = heapq.heappop(self.available)
            return res
        else:
            self.seat += 1
            return self.seat

    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.available, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)

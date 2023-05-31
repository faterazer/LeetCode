class UndergroundSystem:
    def __init__(self):
        self.memo = {}
        self.timer = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.memo[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation, start = self.memo[id]
        key = startStation + " " + stationName
        total, cnt = self.timer.setdefault(key, (0, 0))
        self.timer[key] = (total + t - start, cnt + 1)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        key = startStation + " " + endStation
        total, cnt = self.timer[key]
        return total / cnt


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)

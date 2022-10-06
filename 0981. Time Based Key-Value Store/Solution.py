class TimeMap:
    def __init__(self):
        self.map = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map.setdefault(key, []).append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.map:
            return ""

        arr = self.map.get(key)
        l, r = 0, len(arr) - 1
        while l <= r:
            m = l + (r - l) // 2
            if arr[m][0] <= timestamp:
                l = m + 1
            else:
                r = m - 1
        return arr[r][1] if r >= 0 else ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

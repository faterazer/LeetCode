import random


class RandomizedSet:

    def __init__(self):
        self.data = []
        self.table = {}

    def insert(self, val: int) -> bool:
        if val in self.table:
            return False
        self.table[val] = len(self.data)
        self.data.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.table:
            return False
        idx = self.table.get(val)
        self.table[self.data[-1]] = idx
        self.data[idx], self.data[-1] = self.data[-1], self.data[idx]
        self.data.pop()
        self.table.pop(val)
        return True

    def getRandom(self) -> int:
        return self.data[random.randint(0, len(self.data) - 1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

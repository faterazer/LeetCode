class MyHashSet:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.keyRange = 769
        self.barrel = [[] for i in range(self.keyRange)]

    def add(self, key: int) -> None:
        if not self.contains(key):
            self.barrel[key % self.keyRange].append(key)

    def remove(self, key: int) -> None:
        if self.contains(key):
            self.barrel[key % self.keyRange].remove(key)


    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        return key in self.barrel[key % self.keyRange]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)

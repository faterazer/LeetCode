class MyHashMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.bucket = [[] for _ in range(769)]

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        select = self.bucket[key % len(self.bucket)]
        for i in range(len(select)):
            if select[i][0] == key:
                select[i] = (key, value)
                return
        select.append((key, value))

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        for item in self.bucket[key % len(self.bucket)]:
            if item[0] == key:
                return item[1]
        return -1

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        select = self.bucket[key % len(self.bucket)]
        for item in select:
            if item[0] == key:
                select.remove(item)
                return


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)

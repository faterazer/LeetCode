import heapq
from collections import defaultdict


class NumberContainers:

    def __init__(self):
        self.data = {}  # Maps index to number
        self.num2idx = defaultdict(list)

    def change(self, index: int, number: int) -> None:
        self.data[index] = number
        heapq.heappush(self.num2idx[number], index)

    def find(self, number: int) -> int:
        if number not in self.num2idx:
            return -1
        while self.num2idx[number] and self.data[self.num2idx[number][0]] != number:
            heapq.heappop(self.num2idx[number])
        if not self.num2idx[number]:
            self.num2idx.pop(number, None)
            return -1
        return self.num2idx[number][0]


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)

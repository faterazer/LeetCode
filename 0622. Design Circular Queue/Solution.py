class MyCircularQueue:

    def __init__(self, k: int):
        self.front = 0
        self.rear = 1
        self.len = k + 1
        self.queue = [0] * self.len

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.queue[self.rear] = value
        self.rear = (self.rear + 1) % self.len
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.len
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.queue[(self.front + 1) % self.len]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.queue[(self.rear - 1 + self.len) % self.len]

    def isEmpty(self) -> bool:
        return (self.front + 1) % self.len == self.rear

    def isFull(self) -> bool:
        return self.front == self.rear


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()

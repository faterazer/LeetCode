from collections import deque


class FrontMiddleBackQueue:
    def __init__(self):
        self.q1 = deque([])
        self.q2 = deque([])

    def pushFront(self, val: int) -> None:
        self.q1.appendleft(val)
        if len(self.q1) > len(self.q2):
            self.q2.appendleft(self.q1.pop())

    def pushMiddle(self, val: int) -> None:
        if len(self.q1) == len(self.q2):
            self.q2.appendleft(val)
        else:
            self.q1.append(val)

    def pushBack(self, val: int) -> None:
        self.q2.append(val)
        if len(self.q2) - len(self.q1) == 2:
            self.q1.append(self.q2.popleft())

    def popFront(self) -> int:
        if not self.q1 and not self.q2:
            return -1
        if not self.q1:
            return self.q2.popleft()
        res = self.q1.popleft()
        if len(self.q2) - len(self.q1) == 2:
            self.q1.append(self.q2.popleft())
        return res

    def popMiddle(self) -> int:
        if not self.q1 and not self.q2:
            return -1
        if len(self.q1) == len(self.q2):
            return self.q1.pop()
        else:
            return self.q2.popleft()

    def popBack(self) -> int:
        if not self.q1 and not self.q2:
            return -1
        if not self.q2:
            return self.q1.pop()
        res = self.q2.pop()
        if len(self.q1) - len(self.q2) == 1:
            self.q2.appendleft(self.q1.pop())
        return res


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()

from typing import List


class OrderedStream:

    def __init__(self, n: int):
        self.vs = [None] * n
        self.size = n
        self.ptr = 0

    def insert(self, idKey: int, value: str) -> List[str]:
        i = idKey - 1
        self.vs[i] = value
        res = []
        if i == self.ptr:
            while self.ptr < self.size and self.vs[self.ptr]:
                res.append(self.vs[self.ptr])
                self.ptr += 1
        return res


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)

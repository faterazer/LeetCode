from typing import List


class Vector2D:
    def __init__(self, vec: List[List[int]]):
        def generator():
            for row in vec:
                for ele in row:
                    yield ele

        self.gen = generator()
        self.next_val = next(self.gen, None)

    def next(self) -> int:
        res = self.next_val
        self.next_val = next(self.gen, None)
        return res

    def hasNext(self) -> bool:
        return self.next_val is not None


# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(vec)
# param_1 = obj.next()
# param_2 = obj.hasNext()

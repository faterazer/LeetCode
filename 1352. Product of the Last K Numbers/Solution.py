class ProductOfNumbers:

    def __init__(self) -> None:
        self.buff = []

    def add(self, num: int) -> None:
        if num == 0:
            self.buff.clear()
        elif not self.buff:
            self.buff.append(num)
        else:
            self.buff.append(self.buff[-1] * num)

    def getProduct(self, k: int) -> int:
        if len(self.buff) < k:
            return 0
        elif len(self.buff) == k:
            return self.buff[-1]
        else:
            return self.buff[-1] // self.buff[-k - 1]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)

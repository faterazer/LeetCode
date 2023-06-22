from collections import Counter


class TwoSum:
    def __init__(self):
        self.cnt = Counter()

    def add(self, number: int) -> None:
        self.cnt[number] += 1

    def find(self, value: int) -> bool:
        for k, v in self.cnt.items():
            complement = value - k
            if complement == k:
                if v > 1:
                    return True
            else:
                if complement in self.cnt:
                    return True
        return False


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)

from collections import Counter


class Solution:
    def findEvenNumbers(self, digits: list[int]) -> list[int]:
        cnt = Counter(digits)
        return [i for i in range(100, 1000, 2) if Counter(map(int, str(i))) <= cnt]

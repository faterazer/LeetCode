from collections import Counter


class Solution:
    def numRabbits(self, answers: list[int]) -> int:
        return sum((c + x) // (x + 1) * (x + 1) for x, c in Counter(answers).items())

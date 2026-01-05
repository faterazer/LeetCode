from itertools import chain
from sys import maxsize


class Solution:
    def maxMatrixSum(self, matrix: list[list[int]]) -> int:
        result = 0
        mn = maxsize
        neg_cnt = 0
        for x in chain.from_iterable(matrix):
            result += abs(x)
            neg_cnt += x < 0
            mn = min(mn, abs(x))
        if neg_cnt % 2 == 1:
            result -= 2 * mn
        return result

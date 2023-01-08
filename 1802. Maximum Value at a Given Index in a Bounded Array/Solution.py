import math


class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        left, right = index, n - index - 1
        if left > right:
            left, right = right, left

        upper = left * left + 3 * left + right + 1
        if upper >= maxSum:
            a = 1
            b = -2
            c = left + right + 2 - maxSum
            return math.floor((-b + math.sqrt(b * b - 4 * a * c)) / (2 * a))

        upper = (right * right + 3 * right - left * left + left) / 2 + left * right + 1
        if upper >= maxSum:
            a = 0.5
            b = (2 * left - 1) / 2
            c = right - (left * (left + 1)) / 2 + 1 - maxSum
            return math.floor((-b + math.sqrt(b * b - 4 * a * c)) / (2 * a))
        else:
            a = left + right + 1
            b = (left * left + left + right * right + right) / 2 + maxSum
            return math.floor(b / a)

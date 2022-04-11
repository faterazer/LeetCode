class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        if n == 1:
            return 10
        res, tmp = 10, 9
        for i in range(1, n):
            res += tmp * (9 - i + 1)
            tmp *= 9 - i + 1
        return res

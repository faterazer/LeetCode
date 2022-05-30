INT_MIN = -2 ** 31
INT_MAX = 2 ** 31 - 1


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if divisor == 1:
            return dividend
        if dividend == divisor:
            return 1
        if dividend == 0 or divisor == INT_MIN:
            return 0
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX

        sign = 1 if (dividend >= 0) == (divisor >= 0) else -1
        if dividend == INT_MIN:
            return sign * (1 + self.divide(-(dividend + abs(divisor)), abs(divisor)))

        res = 0
        dividend, divisor = abs(dividend), abs(divisor)
        while dividend >= divisor:
            tmp, cnt = divisor, 1
            while tmp <= INT_MAX >> 1 and (tmp << 1) <= dividend:
                cnt <<= 1
                tmp <<= 1
            res += cnt
            dividend -= tmp
        return res * sign

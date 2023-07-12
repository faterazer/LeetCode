class Solution:
    def alternateDigitSum(self, n: int) -> int:
        res, sign = 0, 1
        while n:
            res += n % 10 * sign
            sign *= -1
            n //= 10
        return res * -sign

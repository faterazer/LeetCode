class Solution:
    def getNoZeroIntegers(self, n: int) -> list[int]:
        res = [0] * 2
        power, digit = 1, 0
        while n:
            if n % 10 > 1 or n < 10:
                digit = n % 10
            else:
                digit = 10 + n % 10
                n -= 10
            res[0] += digit // 2 * power
            res[1] += (digit + 1) // 2 * power
            n //= 10
            power *= 10
        return res

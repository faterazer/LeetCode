class Solution:
    def countDigitOne(self, n: int) -> int:
        res = 0
        power = 1
        tail = 0
        while n:
            tail = n % 10 * power + tail
            res += n // 10 * power + min(max(0, tail - power + 1), power)
            power *= 10
            n //= 10
        return res

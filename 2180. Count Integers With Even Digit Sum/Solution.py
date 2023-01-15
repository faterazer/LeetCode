class Solution:
    def countEven(self, num: int) -> int:
        digit_sum = sum(map(int, str(num)))
        res = num // 10 * 5 - 1
        if digit_sum & 1:
            return res + (num % 10 + 1) // 2
        else:
            return res + num % 10 // 2 + 1

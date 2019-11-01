class Solution:
    def reverse(self, x: int) -> int:
        sign = (x > 0) - (x < 0)
        reversed_x = sign * int(str(sign * x)[::-1])
        return reversed_x if reversed_x.bit_length() < 31 else 0

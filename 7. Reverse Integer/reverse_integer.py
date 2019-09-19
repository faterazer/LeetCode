class Solution:
    def reverse(self, x):
        sign = (x > 0) - (x < 0)
        r = int(str(x * sign)[::-1]) * sign
        return r if r.bit_length() < 32 else 0

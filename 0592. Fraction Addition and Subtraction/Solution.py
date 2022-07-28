import math
import re


class Solution:
    def fractionAddition(self, expression: str) -> str:
        nums = map(int, re.findall('[+-]?\d+', expression))
        A, B = 0, 1
        for a in nums:
            b = next(nums)
            A = A * b + a * B
            B *= b
            g = math.gcd(A, B)
            A //= g
            B //= g
        return f'{A}/{B}'

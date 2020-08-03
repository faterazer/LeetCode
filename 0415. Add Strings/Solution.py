class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = ''
        carry = 0
        i, j = len(num1) - 1, len(num2) - 1
        while i >= 0 or j >= 0:
            a = 0 if i < 0 else int(num1[i])
            b = 0 if j < 0 else int(num2[j])
            carry += a + b
            res += str(carry % 10)
            carry //= 10
            i, j = i - 1, j - 1
        if carry:
            res += '1'
        return res[::-1]

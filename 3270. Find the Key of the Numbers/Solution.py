class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        ans, pow10 = 0, 1
        while num1 and num2 and num3:
            ans += min(num1 % 10, num2 % 10, num3 % 10) * pow10
            num1, num2, num3 = num1 // 10, num2 // 10, num3 // 10
            pow10 *= 10
        return ans

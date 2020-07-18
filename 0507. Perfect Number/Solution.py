class Solution:
    def checkPerfectNumber_MK1(self, num: int) -> bool:
        if num <= 1:
            return False
        accum = 1
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                accum += i + num // i
        return accum == num

    # Euclid-Euler Theorem
    def checkPerfectNumber_MK2(self, num: int) -> bool:
        for i in [2, 3, 5, 7, 13]:
            if num == (2 ** (i - 1)) * (2 ** i - 1):
                return True
        return False

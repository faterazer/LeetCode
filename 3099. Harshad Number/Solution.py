class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        s, y = 0, x
        while y:
            y, d = divmod(y, 10)
            s += d
        return s if x % s == 0 else -1

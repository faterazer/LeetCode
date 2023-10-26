class Solution:
    def countDigits(self, num: int) -> int:
        return sum(num % digit == 0 for digit in map(int, str(num)))

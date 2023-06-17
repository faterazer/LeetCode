class Solution:
    def numberOfCuts(self, n: int) -> int:
        return n if n > 1 and n % 2 == 1 else n // 2

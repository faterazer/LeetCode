class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        div, mod = divmod(time, n - 1)
        return 1 + mod if div % 2 == 0 else n - mod
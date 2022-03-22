class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        div, mod = divmod(k - n, 25)
        if div == n and mod == 0:
            return 'z' * div
        else:
            return 'a' * (n - div - 1) + chr(ord('a') + mod) + 'z' * div

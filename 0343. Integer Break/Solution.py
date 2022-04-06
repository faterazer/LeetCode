class Solution:
    def integerBreak(self, n: int) -> int:
        if n < 4:
            return n - 1
        div, mod = divmod(n, 3)
        if mod == 0:
            return int(3 ** div)
        elif mod == 1:
            return int(3 ** (div - 1)) * 4
        else:
            return int(3 ** div) * 2

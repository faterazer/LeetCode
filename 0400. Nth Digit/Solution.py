class Solution:
    def findNthDigit(self, n: int) -> int:
        digits, nums, base = 1, 9, 0
        while n // digits > nums:
            n -= digits * nums
            digits += 1
            nums *= 10
            base = base * 10 + 9
        d, m = divmod(n, digits)
        res = base + d
        if m:
            res += 1
        return int(str(res)[(m - 1 + digits) % digits])

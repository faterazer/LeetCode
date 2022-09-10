class Solution:
    def preimageSizeFZF(self, k: int) -> int:

        def numOfTrailingZeros(x: int) -> int:
            res = 0
            while x:
                res += x // 5
                x //= 5
            return res

        l, r = 0, 5 * k
        while l <= r:
            m = l + ((r - l) >> 1)
            zeros = numOfTrailingZeros(m)
            if zeros < k:
                l = m + 1
            elif zeros > k:
                r = m - 1
            else:
                return 5
        return 0

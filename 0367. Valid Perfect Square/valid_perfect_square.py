class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        r = self.sqrtByNewton(num)
        return num / r == r

    def sqrtByLinearSearch(self, n: int) -> int:
        i = 1
        while i <= n / i:
            i += 1
        return i - 1
        
    def sqrtByBinarySearch(self, n: int) -> int:
        left, right = 1, n // 2 + 1
        while left <= right:
            mid = left + (right - left) // 2
            if mid < n / mid:
                left = mid + 1
            elif mid > n / mid:
                right = mid - 1
            else:
                return mid
        return right

    def sqrtByNewton(self, n: int) -> int:
        r = n // 2 + 1
        while r > n / r:
            r = (r + n // r) // 2
        return r

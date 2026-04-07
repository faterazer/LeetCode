from math import isqrt


class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        next_dec = [n] * n
        p = n
        for i in range(n - 2, -1, -1):
            if nums[i] > nums[i + 1]:
                p = i
            next_dec[i] = p

        def solve(k: int) -> bool:
            last_max = 0
            for r in range(k - 1, n, k):
                l = r + 1 - k
                m = next_dec[l]
                if m >= r:
                    if last_max > nums[l]:
                        return False
                    last_max = nums[r]
                else:
                    if next_dec[m + 1] < r or last_max > nums[m + 1] or nums[r] > nums[l]:
                        return False
                    last_max = nums[m]
            return True

        result = 0
        for k in range(1, isqrt(n) + 1):
            if n % k == 0:
                if solve(k):
                    result += k
                if k * k < n and solve(n // k):
                    result += n // k
        return result

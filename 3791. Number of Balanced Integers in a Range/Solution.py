from functools import cache


class Solution:
    def countBalanced(self, low: int, high: int) -> int:
        if high < 11:
            return 0
        low = max(low, 11)

        low_s = list(map(int, str(low)))
        high_s = list(map(int, str(high)))
        n = len(high_s)
        low_s = [0] * (n - len(low_s)) + low_s

        @cache
        def dfs(i: int, diff: int, limit_low: bool, limit_high: bool) -> int:
            if i == n:
                return diff == 0
            if abs(diff) > (n - i + 1) // 2 * 9:
                return 0

            lo = low_s[i] if limit_low else 0
            hi = high_s[i] if limit_high else 9
            sign = 1 if i % 2 == 0 else -1
            result = 0
            for d in range(lo, hi + 1):
                result += dfs(i + 1, diff + sign * d, limit_low and d == lo, limit_high and d == hi)
            return result

        return dfs(0, 0, True, True)

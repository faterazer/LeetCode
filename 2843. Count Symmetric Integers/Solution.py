from functools import cache


class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        high = list(map(int, str(high)))
        n = len(high)
        low = list(map(int, str(low).zfill(n)))

        @cache
        def dfs(i: int, start: int, limit_low: bool, limit_high: bool, diff: int) -> int:
            if diff < 0:
                return 0
            if i == n:
                return diff == 0
            
            lo = low[i] if limit_low else 0
            hi = high[i] if limit_high else 9

            if start == -1 and (n - i) % 2 == 1:
                return 0 if lo > 0 else dfs(i + 1, start, True, False, diff)
            
            ans = 0
            is_left = start == -1 or i < (n + start) // 2
            for d in range(lo, hi + 1):
                ans += dfs(
                    i + 1,
                    i if start == -1 and d else start,
                    limit_low and d == lo,
                    limit_high and d == hi,
                    diff + (d if is_left else -d)
                )
            return ans

        return dfs(0, -1, True, True, 0)

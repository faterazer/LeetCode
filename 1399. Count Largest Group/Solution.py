import statistics
from functools import cache


class Solution:
    # 暴力
    def countLargestGroup_MK1(self, n: int) -> int:
        return len(statistics.multimode(sum(map(int, str(i))) for i in range(1, n + 1)))

    # 数位DP
    def countLargestGroup_MK2(self, n: int) -> int:
        s = list(map(int, str(n)))
        m = len(s)

        @cache
        def dfs(i: int, remain: int, limit_high: bool) -> int:
            if i == m:
                return remain == 0

            lo = 0
            hi = s[i] if limit_high else 9
            ans = 0
            for d in range(lo, hi + 1):
                ans += dfs(i + 1, remain - d, limit_high and d == hi)
            return ans

        mx = ans = 0
        for target in range(1, 9 * m + 1):
            cnt = dfs(0, target, True)
            if cnt > mx:
                mx = cnt
                ans = 1
            elif cnt == mx:
                ans += 1
        return ans

from math import inf, isqrt


class Solution:
    def minDifference(self, n: int, k: int) -> list[int]:
        divisors = []
        for i in range(1, isqrt(n) + 1):
            if n % i == 0:
                divisors.append(i)
                if i * i != n:
                    divisors.append(n // i)
        divisors.sort()

        path = [0] * k
        result = []
        min_diff = inf

        def dfs(i: int, target: int, start_idx: int) -> None:
            nonlocal min_diff, result
            if i == k - 1:
                if target - path[0] < min_diff:
                    path[i] = target
                    min_diff = target - path[0]
                    result = path.copy()
                return

            max_d = isqrt(target)
            for idx in range(start_idx, len(divisors)):
                d = divisors[idx]
                if d > max_d or (i > 0 and d - path[0] >= min_diff):
                    break
                if target % d == 0:
                    path[i] = d
                    dfs(i + 1, target // d, idx)

        dfs(0, n, 0)
        return result

from itertools import combinations


class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: list[int], vFences: list[int]) -> int:
        MOD = 10**9 + 7
        if m == n:
            return (m - 1) * (n - 1) % MOD
        if len(hFences) > len(vFences):
            return self.maximizeSquareArea(n, m, vFences, hFences)

        def helper(nums: list[int]) -> set:
            nums.sort()
            return set(y - x for x, y in combinations(nums, 2))

        hFences += [1, m]
        hset = helper(hFences)
        vFences += [1, n]
        vset = helper(vFences)
        side = max(hset & vset, default=0)
        return side * side % MOD if side else -1

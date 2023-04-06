class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        m, n = len(s), len(t)

        def helper(s: str, t: str, i: int, j: int) -> int:
            res = pre = cur = 0
            while i < m and j < n:
                cur += 1
                if s[i] != t[j]:
                    pre, cur = cur, 0
                res += pre
                i += 1
                j += 1
            return res

        res = 0
        for i in range(n):
            res += helper(s, t, 0, i)
        for j in range(1, m):
            res += helper(s, t, j, 0)
        return res

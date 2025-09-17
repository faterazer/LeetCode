class Solution:
    def minTime(self, s: str, order: list[int], k: int) -> int:
        n = len(s)
        cnt = n * (n + 1) // 2
        if cnt < k:
            return -1

        prev = list(range(-1, n - 1))
        next = list(range(1, n + 1))
        for t in range(n - 1, -1, -1):
            i = order[t]
            l, r = prev[i], next[i]
            cnt -= (i - l) * (r - i)
            if cnt < k:
                return t
            if l >= 0:
                next[l] = r
            if r < n:
                prev[r] = l
        return -1

from collections import defaultdict


class Solution:
    def longestBalanced(self, s: str) -> int:
        n, result = len(s), 0
        for i in range(n):
            cnt = defaultdict(int)
            mx = 0
            for j in range(i, n):
                cnt[s[j]] += 1
                mx = max(mx, cnt[s[j]])
                if mx * len(cnt) == j - i + 1:
                    result = max(result, j - i + 1)
            if n - i + 1 <= result:
                break
        return result

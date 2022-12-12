class Solution:
    def beautySum(self, s: str) -> int:
        n, res = len(s), 0
        for i in range(n):
            cnt = [0] * 26
            for j in range(i, n):
                cnt[ord(s[j]) - ord("a")] += 1
                res += max(cnt) - min(e for e in cnt if e > 0)
        return res

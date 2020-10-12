class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        prev, cur, ans = 0, 1, 0
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                ans += min(prev, cur)
                prev = cur
                cur = 0
            cur += 1
        return ans + min(prev, cur)

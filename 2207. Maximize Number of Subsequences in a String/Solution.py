class Solution:
    def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
        cnt0 = cnt1 = res = 0
        for c in text:
            if c == pattern[1]:
                cnt1 += 1
                res += cnt0
            if c == pattern[0]:
                cnt0 += 1
        return res + max(cnt0, cnt1)

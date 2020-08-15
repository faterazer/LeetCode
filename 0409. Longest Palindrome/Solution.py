import collections


class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = 0
        counter = collections.Counter(s)
        for v in counter.values():
            ans += v - (v & 1)
        return ans if ans == len(s) else ans + 1

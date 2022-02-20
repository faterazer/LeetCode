class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = {}
        beg = -1
        res = 0
        for i, c in enumerate(s):
            if c in d and d[c] > beg:
                beg = d[c]
            d[c] = i
            res = max(res, i - beg)
        return res

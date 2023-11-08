class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        res = i = 0
        while i < len(s):
            zeros = ones = 0
            while i < len(s) and s[i] == "0":
                zeros += 1
                i += 1
            while i < len(s) and s[i] == "1":
                ones += 1
                i += 1
            res = max(res, 2 * min(zeros, ones))
        return res

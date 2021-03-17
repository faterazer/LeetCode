class Solution:
    def maxScore(self, s: str) -> int:
        zeros = ones = 0
        res = float('-inf')
        for i in range(len(s)):
            if s[i] == '0':
                zeros += 1
            else:
                ones += 1
            if i != len(s) - 1:
                res = max(res, zeros - ones)
        return res + ones

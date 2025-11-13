class Solution:
    def maxOperations(self, s: str) -> int:
        result = cnt1 = 0
        for i, c in enumerate(s):
            if c == "1":
                cnt1 += 1
            elif i > 0 and s[i - 1] == "1":
                result += cnt1
        return result

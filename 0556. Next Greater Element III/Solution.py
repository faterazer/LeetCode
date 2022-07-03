class Solution:
    def nextGreaterElement(self, n: int) -> int:
        s = [int(c) for c in str(n)]
        i = j = len(s) - 1
        while i > 0 and s[i] <= s[i - 1]:
            i -= 1
        if i == 0:
            return -1
        while s[j] <= s[i - 1]:
            j -= 1
        s[i - 1], s[j] = s[j], s[i - 1]
        s[i:] = reversed(s[i:])
        INT_MAX = 2 ** 31 - 1
        res = 0
        for c in s:
            if res > (INT_MAX - c) // 10:
                return -1
            res = res * 10 + c
        return res

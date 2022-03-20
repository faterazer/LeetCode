import re


class Solution:
    def myAtoi_MK1(self, s: str) -> int:
        i, n = 0, len(s)
        sign, ans = 1, 0
        while i < n and s[i] == ' ':
            i += 1
        if i < n and (s[i] == '+' or s[i] == '-'):
            sign = -1 if s[i] == '-' else 1
            i += 1
        while i < n and s[i].isdigit():
            ans = ans * 10 + int(s[i])
            i += 1
        return max(min(ans * sign, 2 ** 31 - 1), -2 ** 31)

    def myAtoi_MK2(self, s: str) -> int:
        return max(min(int(*re.findall(r'^[+-]?\d+', s.lstrip())), 2**31 - 1), -2**31)

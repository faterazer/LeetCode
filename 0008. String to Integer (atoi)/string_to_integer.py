import re


class Solution:
    def myAtoi_MK1(self, str: str) -> int:
        i, n = 0, len(str)
        sign, ans = 1, 0
        while i < n and str[i] == ' ':
            i += 1
        if i < n and (str[i] == '+' or str[i] == '-'):
            sign = -1 if str[i] == '-' else 1
            i += 1
        while i < n and str[i].isdigit():
            ans = ans * 10 + int(str[i])
            i += 1
        return max(min(ans * sign, 2 ** 31 - 1), -2 ** 31)

    def myAtoi_MK2(self, str: str) -> int:
        return max(min(int(*re.findall(r'^[+-]?\d+', str.lstrip())), 2**31 - 1), -2**31)

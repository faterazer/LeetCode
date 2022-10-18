import itertools


class Solution:
    def countAndSay(self, n: int) -> str:
        res = "1"
        for _ in range(n - 1):
            res = "".join(str(len(list(group))) + digit for digit, group in itertools.groupby(res))
        return res

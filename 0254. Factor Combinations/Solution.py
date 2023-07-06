from typing import List


class Solution:
    def getFactors(self, n: int) -> List[List[int]]:
        res, buff = [], []

        def helper(n: int) -> None:
            i = buff[-1] if buff else 2
            while i <= n // i:
                if n % i == 0:
                    buff.append(i)
                    buff.append(n // i)
                    res.append(buff.copy())
                    buff.pop()
                    helper(n // i)
                    buff.pop()
                i += 1

        helper(n)
        return res

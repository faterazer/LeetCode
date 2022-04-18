from ast import Return
from typing import List


class Solution:
    def lexicalOrder(self, n: int) -> List[int]:

        def nextNum(x: int, limit: int) -> int:
            if x * 10 <= limit:
                return x * 10
            while x + 1 > n or x % 10 == 9:
                x //= 10
            return x + 1

        res = [1]
        while len(res) < n:
            res.append(nextNum(res[-1], n))    
        return res

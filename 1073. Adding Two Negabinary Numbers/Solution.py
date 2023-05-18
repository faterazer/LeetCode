from typing import List


class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        res, carry = [], 0
        while arr1 or arr2 or carry:
            carry += (arr1 or [0]).pop() + (arr2 or [0]).pop()
            res.append(carry & 1)
            carry = -(carry >> 1)
        while len(res) > 1 and res[-1] == 0:
            res.pop()
        return res[::-1]

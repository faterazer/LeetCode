from functools import reduce
from operator import xor
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor_sum = reduce(xor, nums)
        lowbit = xor_sum & -xor_sum
        res = [0, 0]
        for x in nums:
            if (x & lowbit) != 0:
                res[0] ^= x
            else:
                res[1] ^= x
        return res

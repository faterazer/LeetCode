from functools import reduce
from operator import xor


class Solution:
    def doesValidArrayExist(self, derived: list[int]) -> bool:
        return reduce(xor, derived) == 0

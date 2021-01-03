import collections
import functools
import math
from typing import List


class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        vals = collections.Counter(deck).values()
        return functools.reduce(math.gcd, vals) > 1

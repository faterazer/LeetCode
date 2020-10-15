import collections
from functools import reduce
from typing import List


class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        return list(reduce(collections.Counter.__and__, map(collections.Counter, A)).elements())

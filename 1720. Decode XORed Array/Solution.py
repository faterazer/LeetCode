import itertools
from typing import List


class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        return itertools.accumulate([first] + encoded, lambda x, y: x ^ y)

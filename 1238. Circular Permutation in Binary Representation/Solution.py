from typing import List


class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        n = 1 << n
        return [i ^ (i >> 1) ^ start for i in range(n)]

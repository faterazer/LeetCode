from typing import List


class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        return sum(((i + 1) * (n - i) + 1) // 2 * arr[i] for i in range(n))

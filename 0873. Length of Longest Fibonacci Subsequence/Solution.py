import collections
from typing import List


class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        indices = {x: i for i, x in enumerate(arr)}
        dp = collections.defaultdict(lambda: 2)

        res = 0
        for i in range(len(arr)):
            for j in range(i):
                need = arr[i] - arr[j]
                if need <= arr[j]:
                    break
                if need in indices:
                    k = indices[need]
                    dp[k, i] = dp[j, k] + 1
                    res = max(res, dp[k, i])
        return res

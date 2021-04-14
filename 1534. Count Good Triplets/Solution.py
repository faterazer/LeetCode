from typing import List


class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        res = 0
        preSum = [0] * 1001
        for j in range(len(arr)):
            for k in range(j + 1, len(arr)):
                if abs(arr[j] - arr[k]) > b:
                    continue
                l = max(0, arr[j] - a, arr[k] - c)
                r = min(1000, arr[j] + a, arr[k] + c)
                if l <= r:
                    res += preSum[r]
                    if l > 0:
                        res -= preSum[l - 1]
            for x in range(arr[j], 1001):
                preSum[x] += 1
        return res

import bisect
from typing import List


class Solution:
    # Time complexity: O(nlgn)
    def specialArray_MK1(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        for i in range(n):
            X = n - i
            if n - bisect.bisect_left(nums, X) == X:
                return X
        return -1

    # Time complexity: O(n)
    def specialArray_MK2(self, nums: List[int]) -> int:
        n = len(nums)
        counter = [0] * (n + 1)
        for x in nums:
            counter[min(x, n)] += 1

        cnt = 0
        for i in range(n, 0, -1):
            cnt += counter[i]
            if cnt == i:
                return i
        return -1

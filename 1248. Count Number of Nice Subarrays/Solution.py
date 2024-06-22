from typing import List


class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        res = i = cnt = 0
        for j, e in enumerate(nums):
            if e & 1:
                k -= 1
                cnt = 0
            while k == 0:
                k += nums[i] & 1
                i += 1
                cnt += 1
            res += cnt
        return res

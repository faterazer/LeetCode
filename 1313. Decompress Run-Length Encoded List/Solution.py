from typing import List


class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        res = []
        for freq, val in zip(nums[::2], nums[1::2]):
            res += [val] * freq
        return res

from typing import List


class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        res = mask = 0
        high_bit = max(nums).bit_length() - 1
        for i in range(high_bit, -1, -1):
            mask |= 1 << i
            seen = set()
            new_res = res | (1 << i)
            for x in nums:
                x &= mask
                if new_res ^ x in seen:
                    res = new_res
                    break
                seen.add(x)
        return res

from typing import List


class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        nums[::2], nums[1::2] = nums[0:n], nums[n:]
        return nums

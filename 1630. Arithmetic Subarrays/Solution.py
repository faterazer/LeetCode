from typing import List


class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        def check(nums: List[int], left: int, right: int) -> bool:
            len = right - left + 1
            min_val, max_val = min(nums[left : right + 1]), max(nums[left : right + 1])
            seen = set(nums[left : right + 1])
            d, mod = divmod(max_val - min_val, len - 1)
            return mod == 0 and all(min_val + (i - 1) * d in seen for i in range(1, len))

        return [check(nums, left, right) for left, right in zip(l, r)]

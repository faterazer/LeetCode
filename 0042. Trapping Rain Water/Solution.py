from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        res = left = pre_max = suf_max = 0
        right = len(height) - 1
        while left < right:
            pre_max, suf_max = max(pre_max, height[left]), max(suf_max, height[right])
            if pre_max < suf_max:
                res += pre_max - height[left]
                left += 1
            else:
                res += suf_max - height[right]
                right -= 1
        return res

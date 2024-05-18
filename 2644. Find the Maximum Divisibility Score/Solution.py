from itertools import pairwise
from typing import List


class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        nums.sort(reverse=True)
        dup_cnt = sum(a == b for a, b in pairwise(nums))
        divisors.sort()

        max_score, res = -1, 0
        for divisor in divisors:
            if (max_score - dup_cnt + 1) * divisor > nums[0]:
                break

            score = 0
            for n in nums:
                if n < divisor:
                    break
                score += n % divisor == 0

            if score > max_score:
                max_score, res = score, divisor
        return res

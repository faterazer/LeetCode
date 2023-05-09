from typing import List


class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        def helper(firstLen: int, secondLen: int) -> int:
            first_sum, second_sum = sum(nums[:firstLen]), sum(nums[firstLen : firstLen + secondLen])
            max_first_sum, res = first_sum, first_sum + second_sum
            for i in range(firstLen, len(nums) - secondLen):
                first_sum += nums[i] - nums[i - firstLen]
                max_first_sum = max(max_first_sum, first_sum)
                second_sum += nums[i + secondLen] - nums[i]
                res = max(res, max_first_sum + second_sum)
            return res

        return max(helper(firstLen, secondLen), helper(secondLen, firstLen))

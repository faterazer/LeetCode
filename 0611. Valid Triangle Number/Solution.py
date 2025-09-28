from typing import List


class Solution:
    def triangleNumber_MK1(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        for k in range(len(nums) - 1, 1, -1):
            if nums[0] + nums[1] > nums[k]:
                ans += (k + 1) * k * (k - 1) // 6
                break
            if nums[k - 2] + nums[k - 1] <= nums[k]:
                continue
            i, j = 0, k - 1
            while i < j:
                if nums[i] + nums[j] > nums[k]:
                    ans += j - i
                    j -= 1
                else:
                    i += 1
        return ans

    def triangleNumber_MK2(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        for i in range(len(nums) - 2):
            if nums[i] == 0:
                continue
            j = i + 1
            for k in range(i + 2, len(nums)):
                while j < k and nums[i] + nums[j] <= nums[k]:
                    j += 1
                ans += k - j
        return ans

class Solution:
    # LogTrick
    def smallestSubarrays_MK1(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = [1] * n
        for i in range(1, len(nums)):
            for j in range(i - 1, -1, -1):
                if nums[j] | nums[i] == nums[j]:
                    break
                nums[j] |= nums[i]
                ans[j] = i - j + 1
        return ans

    # 滑动窗口 + 栈
    def smallestSubarrays_MK2(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = [1] * n
        left_or, bottom, right = 0, n - 2, n - 1
        for left in range(n - 2, -1, -1):
            left_or |= nums[left]
            while right > left and (left_or | nums[right]) == (left_or | nums[right - 1]):
                right -= 1
                if bottom >= right:
                    for i in range(left + 1, right + 1):
                        nums[i] |= nums[i - 1]
                    bottom = left
                    left_or = 0
            ans[left] = right - left + 1
        return ans

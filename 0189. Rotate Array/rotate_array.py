from typing import List


class Solution:
    def rotate_MK1(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        self.reverse(nums, 0, len(nums) - 1)
        self.reverse(nums, 0, k - 1);
        self.reverse(nums, k, len(nums) - 1)

    def reverse(self, nums: List[int], begin: int, end: int) -> None:
        while begin < end:
            nums[begin], nums[end] = nums[end], nums[begin]
            begin += 1
            end -= 1

    def rotate_MK2(self, nums: List[int], k: int) -> None:
        k %= len(nums)
        count, start = 0, 0
        while count < len(nums):
            prev, curr, tmp = nums[start], (start + k) % len(nums), nums[start]
            while curr != start:
                tmp = nums[curr]
                nums[curr] = prev
                prev = tmp
                curr = (curr + k) % len(nums)
                count += 1
            nums[start] = tmp
            count += 1
            start += 1

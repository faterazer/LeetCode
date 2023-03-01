from typing import List


class Solution:
    def quickSort(self, nums: List[int], left: int, right: int) -> None:
        if left >= right:
            return
        if all(nums[i] == nums[left] for i in range(left + 1, right + 1)):
            return

        mid = left + ((right - left) >> 1)
        nums[left], nums[mid] = nums[mid], nums[left]
        pivot, last = nums[left], left
        for i in range(left + 1, right + 1):
            if nums[i] < pivot:
                last += 1
                nums[i], nums[last] = nums[last], nums[i]
        nums[left], nums[last] = nums[last], nums[left]
        self.quickSort(nums, left, last - 1)
        self.quickSort(nums, last + 1, right)

    def sortArray_MK1(self, nums: List[int]) -> List[int]:
        """
        Quick Sort
        """
        self.quickSort(nums, 0, len(nums) - 1)
        return nums

    def merge(self, nums: List[int], low: int, mid: int, high: int) -> None:
        left = []
        for i in range(low, mid + 1):
            left.append(nums[i])
        left.append(float("inf"))
        right = []
        for i in range(mid + 1, high + 1):
            right.append(nums[i])
        right.append(float("inf"))
        i, j = 0, 0
        for k in range(low, high + 1):
            if left[i] <= right[j]:
                nums[k] = left[i]
                i += 1
            else:
                nums[k] = right[j]
                j += 1

    def mergeSort(self, nums: List[int], low: int, high: int) -> None:
        if low >= high:
            return
        mid = (low + high) // 2
        self.mergeSort(nums, low, mid)
        self.mergeSort(nums, mid + 1, high)
        self.merge(nums, low, mid, high)

    def sortArray_MK2(self, nums: List[int]) -> List[int]:
        """
        Merge Sort
        """
        self.mergeSort(nums, 0, len(nums) - 1)
        return nums

import random
from typing import List


class Solution:
    def quickSort(self, nums: List[int], left: int, right: int) -> None:
        if left >= right:
            return
        rand_idx = random.randint(left, right)
        pivoit = nums[rand_idx]
        nums[left], nums[rand_idx] = nums[rand_idx], nums[left]
        i, j, k = left + 1, left, right + 1
        while i < k:
            if nums[i] < pivoit:
                nums[i], nums[j + 1] = nums[j + 1], nums[i]
                j += 1
                i += 1
            elif nums[i] > pivoit:
                nums[i], nums[k - 1] = nums[k - 1], nums[i]
                k -= 1
            else:
                i += 1
        nums[left], nums[j] = nums[j], nums[left]
        self.quickSort(nums, left, j - 1)
        self.quickSort(nums, k, right)

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

    def siftDown(self, nums: List[int], start: int, end: int) -> None:
        parent = start
        child = parent * 2 + 1
        while child <= end:
            if child + 1 <= end and nums[child] < nums[child + 1]:
                child += 1
            if nums[parent] >= nums[child]:
                return
            else:
                nums[parent], nums[child] = nums[child], nums[parent]
                parent = child
                child = parent * 2 + 1

    def sortArray_MK3(self, nums: List[int]) -> List[int]:
        n = len(nums)
        i = (n - 2) // 2
        while i >= 0:
            self.siftDown(nums, i, n - 1)
            i -= 1

        i = len(nums) - 1
        while i > 0:
            nums[0], nums[i] = nums[i], nums[0]
            i -= 1
            self.siftDown(nums, 0, i)
        return nums

    def sortArray_MK4(self, nums: List[int]) -> List[int]:
        n = len(nums)
        step = n // 2
        while step > 0:
            for i in range(step, n):
                j = i - step
                while j >= 0 and nums[j] > nums[j + step]:
                    nums[j], nums[j + step] = nums[j + step], nums[j]
                    j -= step
            step //= 2
        return nums

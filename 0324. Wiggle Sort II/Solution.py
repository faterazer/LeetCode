from typing import List


class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def kthElement(arr: List[int], l: int, k: int, r: int) -> None:
            if l >= r or k < l or k > r:
                return
            last = l
            for i in range(l + 1, r + 1):
                if arr[i] <= arr[l]:
                    last += 1
                    arr[i], arr[last] = arr[last], arr[i]
            arr[l], arr[last] = arr[last], arr[l]
            if k < last:
                kthElement(arr, l, k, last - 1)
            elif k > last:
                kthElement(arr, last + 1, k, r)

        n = len(nums)
        mid_idx = n // 2
        kthElement(nums, 0, mid_idx, len(nums) - 1)
        mid = nums[mid_idx]

        def idxMapping(x: int) -> int:
            return (2 * x + 1) % (n | 1)

        i, j, k = 0, 0, n - 1
        while j <= k:
            J = idxMapping(j)
            if nums[J] > mid:
                I = idxMapping(i)
                nums[I], nums[J] = nums[J], nums[I]
                i += 1
                j += 1
            elif nums[J] < mid:
                K = idxMapping(k)
                nums[K], nums[J] = nums[J], nums[K]
                k -= 1
            else:
                j += 1

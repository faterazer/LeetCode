from typing import List


class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        
        def kth_element(arr: List[int], l: int, k: int, r: int) -> None:
            if all(arr[i] == arr[l] for i in range(l + 1, r + 1)):
                return
            if l >= r or k < l or k > r:
                return
            last = l
            for i in range(l + 1, r + 1):
                if arr[i] <= arr[l]:
                    last += 1
                    arr[i], arr[last] = arr[last], arr[i]
            arr[l], arr[last] = arr[last], arr[l]
            if k < last:
                kth_element(arr, l, k, last - 1)
            elif k > last:
                kth_element(arr, last + 1, k, r)
        
        n = len(nums)
        mid = n // 2
        kth_element(nums, 0, mid, n - 1)
        return sum(abs(e - nums[mid]) for e in nums)

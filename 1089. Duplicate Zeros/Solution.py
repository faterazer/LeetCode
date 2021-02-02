from typing import List


class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        zeros = arr.count(0)
        for i in range(len(arr) - 1, -1, -1):
            if i + zeros < len(arr):
                arr[i + zeros] = arr[i]
            if not arr[i]:
                zeros -= 1
                if i + zeros < len(arr):
                    arr[i + zeros] = arr[i]
            if not zeros:
                break

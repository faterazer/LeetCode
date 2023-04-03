from typing import List


class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        i = len(arr) - 1
        while i > 0 and arr[i] >= arr[i - 1]:
            i -= 1
        if i == 0:
            return arr
        i, j = i - 1, len(arr) - 1
        while arr[j] >= arr[i] or arr[j] == arr[j - 1]:
            j -= 1
        arr[i], arr[j] = arr[j], arr[i]
        return arr

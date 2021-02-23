from typing import List


class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        maxE = -1
        for i in range(len(arr) - 1, -1, -1):
            arr[i], maxE = maxE, max(arr[i], maxE)
        return arr

from typing import List


class Solution:
    def trimMean_MK1(self, arr: List[int]) -> float:
        beg = len(arr) // 20
        end = len(arr) - beg
        return sum(sorted(arr)[beg:end]) / (len(arr) * 0.9)

    def trimMean_MK2(self, arr: List[int]) -> float:

        def kth_element(arr: List[int], l: int, k: int, r: int) -> None:
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

        n = len(arr)
        seg = n // 20
        kth_element(arr, 0, seg, n - 1)
        kth_element(arr, seg, n - seg, n - 1)
        return sum(arr[seg:n-seg]) / (n * 0.9)

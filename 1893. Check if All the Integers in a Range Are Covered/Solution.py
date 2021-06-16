from typing import List


class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        n, cnt = right - left + 1, 0
        arr = [0] * n
        for l, r in ranges:
            if l < left:
                cnt += 1
            elif l <= right:
                arr[l - left] += 1
            if r < left:
                cnt -= 1
            elif r < right:
                arr[r - left + 1] -= 1
        for x in arr:
            cnt += x
            if not cnt:
                return False
        return True

from typing import List


class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        goal, cnt = (k - 1) * m, 0
        for i in range(len(arr) - m):
            cnt = cnt + 1 if arr[i] == arr[i + m] else 0
            if cnt == goal:
                return True
        return False

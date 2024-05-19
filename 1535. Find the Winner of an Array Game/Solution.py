from typing import List


class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        res, cnt = arr[0], -1
        for x in arr:
            if x > res:
                res = x
                cnt = 0
            cnt += 1
            if cnt == k:
                break
        return res

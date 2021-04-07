from typing import List


class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        cnt = 0
        for x in arr:
            cnt = cnt + 1 if x & 1 else 0
            if cnt == 3:
                return True
        return False

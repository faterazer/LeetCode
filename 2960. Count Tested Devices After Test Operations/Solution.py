from typing import List


class Solution:
    def countTestedDevices(self, batteryPercentages: List[int]) -> int:
        res = 0
        for bp in batteryPercentages:
            if bp > res:
                res += 1
        return res

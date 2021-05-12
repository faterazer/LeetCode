from typing import List


class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        res = 0
        for box, unit in sorted(boxTypes, key=lambda x: -x[1]):
            if box < truckSize:
                res += box * unit
                truckSize -= box
            else:
                res += truckSize * unit
                break
        return res

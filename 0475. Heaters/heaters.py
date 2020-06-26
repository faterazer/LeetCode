import bisect
from typing import List


class Solution:
    def findRadius_MK1(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        i, radius = 0, 0
        for house in houses:
            while i < len(heaters) - 1 and heaters[i] + heaters[i + 1] < 2 * house:
                i += 1
            radius = max(radius, abs(house - heaters[i]))
        return radius

    def findRadius_MK2(self, houses: List[int], heaters: List[int]) -> int:
        heaters.sort()
        radius = 0
        for house in houses:
            index = bisect.bisect(heaters, house)
            if index == len(heaters):
                radius = max(radius, house - heaters[-1])
            elif index == 0:
                radius = max(radius, heaters[0] - house)
            else:
                radius = max(radius, min(house - heaters[index-1], heaters[index] - house))
        return radius

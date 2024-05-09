from typing import List


class Solution:
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        res, n = 0, len(plants)
        water_a, water_b = capacityA, capacityB
        i, j = 0, n - 1
        while i <= j:
            if i == j:
                res += max(water_a, water_b) < plants[i]
            else:
                if water_a < plants[i]:
                    water_a = capacityA
                    res += 1
                if water_b < plants[j]:
                    water_b = capacityB
                    res += 1
                water_a -= plants[i]
                water_b -= plants[j]
            i += 1
            j -= 1
        return res

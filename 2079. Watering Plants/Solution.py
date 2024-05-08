from typing import List


class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        res, water = len(plants), capacity
        for i, need in enumerate(plants):
            if water < need:
                res += i * 2
                water = capacity
            water -= need
        return res

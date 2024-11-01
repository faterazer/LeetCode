from typing import List


class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        A = B = 0
        for a, b in zip(energyDrinkA, energyDrinkB):
            A, B = max(a + A, B), max(A, b + B)
        return max(A, B)

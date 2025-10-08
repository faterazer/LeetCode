import bisect


class Solution:
    def successfulPairs(self, spells: list[int], potions: list[int], success: int) -> list[int]:
        potions.sort()
        return [len(potions) - bisect.bisect_right(potions, (success - 1) // spell) for spell in spells]

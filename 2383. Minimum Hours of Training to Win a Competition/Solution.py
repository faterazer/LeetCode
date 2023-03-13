from typing import List


class Solution:
    def minNumberOfHours(
        self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]
    ) -> int:
        res = max(sum(energy) + 1 - initialEnergy, 0)
        for exp in experience:
            if exp >= initialExperience:
                res += exp + 1 - initialExperience
                initialExperience = exp + 1
            initialExperience += exp
        return res

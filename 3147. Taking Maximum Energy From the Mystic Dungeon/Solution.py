from itertools import accumulate


class Solution:
    def maximumEnergy(self, energy: list[int], k: int) -> int:
        return max((max(accumulate(energy[i::k][::-1])) for i in range(k)), default=0)

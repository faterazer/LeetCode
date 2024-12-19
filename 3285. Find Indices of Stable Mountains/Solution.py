from typing import List


class Solution:
    def stableMountains(self, height: List[int], threshold: int) -> List[int]:
        return [i for i, h in enumerate(height[:-1], 1) if h > threshold]

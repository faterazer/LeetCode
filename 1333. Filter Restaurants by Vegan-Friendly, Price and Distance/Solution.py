from typing import List


class Solution:
    def filterRestaurants(
        self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int
    ) -> List[int]:
        filtered = [r for r in restaurants if r[2] >= veganFriendly and r[3] <= maxPrice and r[4] <= maxDistance]
        return [f[0] for f in sorted(filtered, key=lambda x: (-x[1], -x[0]))]

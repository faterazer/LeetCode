from math import isqrt


class Solution:
    def repairCars(self, ranks: list[int], cars: int) -> int:
        left, right = 0, min(ranks) * cars * cars
        while left < right:
            mid = left + (right - left) // 2
            if sum(isqrt(mid // r) for r in ranks) >= cars:
                right = mid
            else:
                left = mid + 1
        return left

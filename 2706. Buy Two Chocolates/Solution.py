from typing import List
from math import inf


class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        min1 = min2 = inf
        for price in prices:
            if price <= min1:
                min1, min2 = price, min1
            elif price < min2:
                min2 = price
        cost = min1 + min2
        return money if cost > money else money - cost

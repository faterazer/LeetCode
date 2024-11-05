from functools import lru_cache
from typing import List, Tuple


class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        n = len(price)
        filtered_special = []
        for offer in special:
            cnt = direct_price = 0
            for i in range(n):
                cnt += offer[i]
                direct_price += offer[i] * price[i]
            if cnt > 0 and direct_price > offer[n]:
                filtered_special.append(offer)

        @lru_cache()
        def dfs(state: Tuple[int]) -> int:
            min_price = sum(state[i] * price[i] for i in range(n))
            for offer in filtered_special:
                next_state = tuple(x - offer[i] for i, x in enumerate(state))

                if all(x >= 0 for x in next_state):
                    min_price = min(min_price, offer[n] + dfs(next_state))
            return min_price

        return dfs(tuple(needs))

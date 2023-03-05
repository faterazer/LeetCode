from typing import List


class Solution:
    def minOperationsMaxProfit(
        self, customers: List[int], boardingCost: int, runningCost: int
    ) -> int:
        if 4 * boardingCost < runningCost:
            return -1

        max_profit = cur_profit = run = wait = i = 0
        res = -1
        n = len(customers)
        while wait or i < n:
            if i < n:
                wait += customers[i]
                i += 1
            run += 1
            cur_profit += min(wait, 4) * boardingCost - runningCost
            if cur_profit > max_profit:
                max_profit = cur_profit
                res = run
            wait = max(0, wait - 4)
        return res

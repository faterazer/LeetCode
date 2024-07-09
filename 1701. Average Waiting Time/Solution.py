from typing import List


class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        cur_time, res = 0, 0
        for a, t in customers:
            cur_time = max(cur_time, a) + t
            res += cur_time - a
        return res / len(customers)

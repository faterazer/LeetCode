from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        res = inc = pre = 1
        dec = 0
        for i in range(1, len(ratings)):
            if ratings[i] >= ratings[i - 1]:
                dec = 0
                pre = pre + 1 if ratings[i] > ratings[i - 1] else 1
                inc = pre
                res += pre
            else:
                dec += 1
                if dec == inc:
                    dec += 1
                pre = 1
                res += dec
        return res

from typing import List


class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        missing_sum = mean * (len(rolls) + n) - sum(rolls)
        if missing_sum < n or missing_sum > 6 * n:
            return []
        div, mod = divmod(missing_sum, n)
        res = [div] * n
        for i in range(mod):
            res[i] += 1
        return res

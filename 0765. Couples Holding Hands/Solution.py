from typing import List


class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        pos = [0] * len(row)
        for i, e in enumerate(row):
            pos[e] = i

        res = 0
        get_partner = lambda x: x ^ 1
        for i in range(0, len(row) - 1, 2):
            partner, j = get_partner(row[i]), i + 1
            while row[j] != partner:
                partner2 = get_partner(row[j])
                pos2 = pos[partner2] ^ 1
                pos[row[j]], pos[partner2] = pos[partner2], pos[row[j]]
                row[j], row[pos2] = row[pos2], row[j]
                res += 1
        return res

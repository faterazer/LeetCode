from typing import List

class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        buff = [(min(a, b), max(a, b)) for a, b in zip(row[::2], row[1::2])]
        buff.sort(key=lambda x: x[0])
        
        row = []
        for a, b in buff:
            row.append(a)
            row.append(b)
        
        res = 0
        for i in range(len(row)):
            while row[i] != i:
                row[i], row[row[i]] = row[row[i]], row[i]
                res += 1
        return res

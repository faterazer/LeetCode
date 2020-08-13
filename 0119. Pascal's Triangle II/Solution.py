from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = [0] * (rowIndex + 1)
        row[0] = 1
        for i in range(rowIndex):
            for j in range(i + 1, 0, -1):
                row[j] += row[j-1]
        return row

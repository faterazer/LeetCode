from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ret = [[1] * (i+1) for i in range(numRows)]
        for i in range(numRows):
            for j in range(1, i):
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j]
        return ret

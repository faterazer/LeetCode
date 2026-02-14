class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        row = [0] * (query_row + 1)
        row[0] = poured
        for i in range(0, query_row):
            for j in range(i, -1, -1):
                excess = max(0.0, row[j] - 1.0)
                if excess > 0:
                    row[j + 1] += excess / 2
                    row[j] = excess / 2
                else:
                    row[j] = 0
        return min(1.0, row[query_glass])

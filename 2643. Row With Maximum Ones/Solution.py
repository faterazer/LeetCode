class Solution:
    def rowAndMaximumOnes(self, mat: list[list[int]]) -> list[int]:
        idx = max_ones = -1
        for i, row in enumerate(mat):
            ones = sum(row)
            if ones > max_ones:
                idx, max_ones = i, ones
        return [idx, max_ones]

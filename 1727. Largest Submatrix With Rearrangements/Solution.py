class Solution:
    def largestSubmatrix(self, matrix: list[list[int]]) -> int:
        n = len(matrix[0])
        heights = [0] * n
        ids = list(range(n))
        result = 0
        for row in matrix:
            zeros, non_zeros = [], []
            for j in ids:
                if row[j] == 0:
                    heights[j] = 0
                    zeros.append(j)
                else:
                    heights[j] += 1
                    non_zeros.append(j)
            ids = zeros + non_zeros
            for i in range(len(zeros), n):
                result = max(result, (n - i) * (heights[ids[i]]))
        return result

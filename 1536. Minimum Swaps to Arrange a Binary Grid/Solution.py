class Solution:
    def minSwaps(self, grid: list[list[int]]) -> int:
        n = len(grid)
        tail_zeros = [next((i for i, val in enumerate(reversed(row)) if val == 1), n) for row in grid]
        result = 0
        for i in range(n):
            target = n - 1 - i
            try:
                j = next(k for k in range(i, n) if tail_zeros[k] >= target)
            except StopIteration:
                return -1
            result += j - i
            if j > i:
                tail_zeros.insert(i, tail_zeros.pop(j))
        return result

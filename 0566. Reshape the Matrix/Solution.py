from typing import List
import itertools


class Solution:
    def matrixReshape_MK1(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(nums), len(nums[0])
        if m * n != r * c:
            return nums
        matrix = [[0] * c for _ in range(r)] 
        for i in range(m * n):
            matrix[i // c][i % c] = nums[i // n][i % n]
        return matrix

    def matrixReshape_MK2(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        flat = list(itertools.chain(*nums))
        # flat = sum(nums, [])
        if len(flat) != r * c:
            return nums
        return [flat[i*c:(i+1)*c] for i in range(r)]

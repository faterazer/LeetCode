from typing import List


class NumArray:

    def __init__(self, nums: List[int]):
        self.sum_list = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            self.sum_list[i + 1] = self.sum_list[i] + nums[i]

    def sumRange(self, i: int, j: int) -> int:
        return self.sum_list[j + 1] - self.sum_list[i]

        # Your NumArray object will be instantiated and called as such:
        # obj = NumArray(nums)
        # param_1 = obj.sumRange(i,j)

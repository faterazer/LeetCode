from typing import List


class NumArray_Binary_Indexed_Tree:
    def __init__(self, nums: List[int]):
        self.tree = [0] * (len(nums) + 1)
        self.data = [0] * len(nums)
        for i, e in enumerate(nums):
            self.update(i, e)

    def update(self, index: int, val: int) -> None:
        diff = val - self.data[index]
        self.data[index] = val
        index += 1
        while index < len(self.tree):
            self.tree[index] += diff
            index += NumArray_Binary_Indexed_Tree.lowbit(index)

    def query(self, index: int) -> int:
        res = 0
        while index > 0:
            res += self.tree[index]
            index -= NumArray_Binary_Indexed_Tree.lowbit(index)
        return res

    def sumRange(self, left: int, right: int) -> int:
        return self.query(right + 1) - self.query(left)

    @staticmethod
    def lowbit(x: int) -> int:
        return x & -x


class NumArray_Segment_Tree:
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.tree = [0] * (2 * self.n)
        for i in range(self.n, len(self.tree)):
            self.tree[i] = nums[i - self.n]
        for i in range(self.n - 1, -1, -1):
            self.tree[i] = self.tree[i << 1] + self.tree[i << 1 | 1]

    def update(self, index: int, val: int) -> None:
        index += self.n
        diff = val - self.tree[index]
        while index > 0:
            self.tree[index] += diff
            index >>= 1

    def sumRange(self, left: int, right: int) -> int:
        left += self.n
        right += self.n
        res = 0
        while left <= right:
            if left & 1 == 1:
                res += self.tree[left]
                left += 1
            if right & 1 == 0:
                res += self.tree[right]
                right -= 1
            left >>= 1
            right >>= 1
        return res


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)

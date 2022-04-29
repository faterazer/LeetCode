from typing import List


class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight


class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def helper(grid: List[List[int]], x: int, y: int, len: int) -> 'Node':
            if len == 1:
                return Node(grid[x][y], True)
            res = Node()
            len //= 2
            topLeft = helper(grid, x, y, len)
            topRight = helper(grid, x, y + len, len)
            bottomLeft = helper(grid, x + len, y, len)
            bottomRight = helper(grid, x + len, y + len, len)
            if topLeft.isLeaf and topRight.isLeaf and bottomLeft.isLeaf and bottomRight.isLeaf and topLeft.val == topRight.val == bottomLeft.val == bottomRight.val:
                res.val = topLeft.val
                res.isLeaf = True
            else:
                res.topLeft = topLeft
                res.topRight = topRight
                res.bottomLeft = bottomLeft
                res.bottomRight = bottomRight
            return res
        
        return helper(grid, 0, 0, len(grid))

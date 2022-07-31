from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        res, max_sum, level = 0, float('-inf'), 0
        queue = deque([root])
        while queue:
            level += 1
            n, tmp_sum = len(queue), 0
            for _ in range(n):
                node = queue.popleft()
                tmp_sum += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if tmp_sum > max_sum:
                max_sum = tmp_sum
                res = level
        return res

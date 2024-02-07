from collections import deque
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        root.val = 0
        queue = deque([root])
        while queue:
            row_sum = sum((node.left.val if node.left else 0) + (node.right.val if node.right else 0) for node in queue)
            n = len(queue)
            for _ in range(n):
                node = queue.popleft()
                children_sum = (node.left.val if node.left else 0) + (node.right.val if node.right else 0)
                if node.left:
                    node.left.val = row_sum - children_sum
                    queue.append(node.left)
                if node.right:
                    node.right.val = row_sum - children_sum
                    queue.append(node.right)
        return root

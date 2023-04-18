from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def dfs(root: TreeNode, min_val: int, max_val: int) -> int:
            if not root:
                return max_val - min_val
            min_val, max_val = min(min_val, root.val), max(max_val, root.val)
            return max(dfs(root.left, min_val, max_val), dfs(root.right, min_val, max_val))

        return dfs(root, root.val, root.val)

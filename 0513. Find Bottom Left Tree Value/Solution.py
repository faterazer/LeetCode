from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        res = max_depth = -1

        def dfs(root: TreeNode, depth: int) -> None:
            if not root:
                return

            nonlocal res, max_depth
            if depth > max_depth:
                max_depth = depth
                res = root.val
            dfs(root.left, depth + 1)
            dfs(root.right, depth + 1)
        
        dfs(root, 0)
        return res

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        max_depth = -1
        res = 0

        def dfs(root: TreeNode, depth: int) -> None:
            nonlocal max_depth, res
            if not root:
                return
            if depth > max_depth:
                max_depth = depth
                res = root.val
            elif depth == max_depth:
                res += root.val
            dfs(root.left, depth + 1)
            dfs(root.right, depth + 1)

        dfs(root, 0)
        return res

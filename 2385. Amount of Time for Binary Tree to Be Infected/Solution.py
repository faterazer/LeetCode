from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        res = 0

        def dfs(node: TreeNode) -> int:
            if node is None:
                return 0

            nonlocal res
            ldepth, rdepth = dfs(node.left), dfs(node.right)
            if node.val == start:
                res = -min(ldepth, rdepth)
                return 1
            if ldepth > 0 or rdepth > 0:
                res = max(res, abs(ldepth) + abs(rdepth))
                return max(ldepth, rdepth) + 1
            else:
                return min(ldepth, rdepth) - 1

        dfs(root)
        return res

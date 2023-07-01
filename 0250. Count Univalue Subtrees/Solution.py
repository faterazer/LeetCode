from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def countUnivalSubtrees(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(node: TreeNode) -> bool:
            if not node:
                return True

            nonlocal res
            lflag, rflag = dfs(node.left), dfs(node.right)
            if lflag and rflag:
                if node.left and node.left.val != node.val:
                    return False
                if node.right and node.right.val != node.val:
                    return False
                res += 1
                return True
            return False

        dfs(root)
        return res

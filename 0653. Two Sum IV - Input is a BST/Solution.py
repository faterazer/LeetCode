from typing import Set


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        def dfs(root: TreeNode, k: int, occured: Set[int]) -> bool:
            if not root:
                return False
            if (k - root.val) in occured:
                return True
            occured.add(root.val)
            return dfs(root.left, k, occured) or dfs(root.right, k, occured)
        occured = set()
        return dfs(root, k, occured)

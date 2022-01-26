from tkinter.tix import Tree
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        path = []
        
        def dfs(root: TreeNode, targetSum: int) -> None:
            if not root:
                return
            targetSum -= root.val
            path.append(root.val)
            if not targetSum and not root.left and not root.right:
                res.append(path.copy())
            if root.left:
                dfs(root.left, targetSum)
            if root.right:
                dfs(root.right, targetSum)
            path.pop()
        
        dfs(root, targetSum)
        return res

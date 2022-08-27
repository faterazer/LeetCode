from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        buff = []
        res = 0

        def dfs(root: TreeNode, idx: int, depth: int) -> None:
            if not root:
                return
            if len(buff) < depth + 1:
                buff.append(idx)
            nonlocal res
            res = max(res, idx - buff[depth] + 1)
            dfs(root.left, idx << 1, depth + 1)
            dfs(root.right, idx << 1 | 1, depth + 1)

        dfs(root, 1, 0)
        return res

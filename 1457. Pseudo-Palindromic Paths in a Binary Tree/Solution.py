from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pseudoPalindromicPaths(self, root: Optional[TreeNode], cnt: int = 0) -> int:
        if not root:
            return 0
        cnt ^= 1 << (root.val - 1)
        res = self.pseudoPalindromicPaths(root.left, cnt) + self.pseudoPalindromicPaths(root.right, cnt)
        if not root.left and not root.right and (cnt & (cnt - 1)) == 0:
            res += 1
        return res

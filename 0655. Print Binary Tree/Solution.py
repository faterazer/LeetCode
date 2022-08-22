from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:

        def depth(root: TreeNode) -> int:
            if not root:
                return 0
            return max(depth(root.left), depth(root.right)) + 1

        def helper(root: TreeNode, l: int, r: int, res: List[List[str]], d: int) -> None:
            if not root or l > r:
                return
            m = l + ((r - l) >> 1)
            res[d][m] = str(root.val)
            helper(root.left, l, m - 1, res, d + 1)
            helper(root.right, m + 1, r, res, d + 1)

        h = depth(root)
        m, n = h, 2 ** h - 1
        res = [[""] * n for _ in range(m)]
        helper(root, 0, n - 1, res, 0)
        return res

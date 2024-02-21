from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:

        def build(inorder_l: int, inorder_r: int, postorder_idx: int) -> TreeNode:
            if inorder_l > inorder_r or postorder_idx < 0:
                return None

            root = TreeNode(postorder[postorder_idx])
            m = inorder.index(root.val, inorder_l, inorder_r + 1)
            root.left = build(inorder_l, m - 1, postorder_idx - inorder_r + m - 1)
            root.right = build(m + 1, inorder_r, postorder_idx - 1)
            return root

        return build(0, len(inorder) - 1, len(postorder) - 1)

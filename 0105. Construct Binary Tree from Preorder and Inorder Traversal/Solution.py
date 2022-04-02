from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:

        def builder(preorder: List[int], idx: int, inorder: List[int], l: int, r: int) -> TreeNode:
            if idx < 0 or idx >= len(preorder) or l > r:
                return None
            root = TreeNode(preorder[idx])
            m = inorder.index(preorder[idx])
            root.left = builder(preorder, idx + 1, inorder, l, m - 1)
            root.right = builder(preorder, idx + m - l + 1, inorder, m + 1, r)
            return root
        
        return builder(preorder, 0, inorder, 0, len(inorder) - 1)

from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:

        def buildTree(pre_l: int, pre_r: int, post_l: int, post_r: int) -> TreeNode:
            if pre_l > pre_r or post_l > post_r:
                return None

            root = TreeNode(preorder[pre_l])
            if pre_l == pre_r:
                return root
            pre_l += 1
            post_r -= 1

            m = postorder.index(preorder[pre_l], post_l, post_r + 1)
            root.left = buildTree(pre_l, pre_l + m - post_l, post_l, m)
            root.right = buildTree(pre_l + m - post_l + 1, pre_r, m + 1, post_r)
            return root

        return buildTree(0, len(preorder) - 1, 0, len(postorder) - 1)

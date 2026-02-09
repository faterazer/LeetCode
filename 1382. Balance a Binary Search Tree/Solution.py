from __future__ import annotations

from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val: int = 0, left: Optional[TreeNode] = None, right: Optional[TreeNode] = None) -> None:
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        buffer = []

        def in_order(node: Optional[TreeNode]) -> None:
            if node is None:
                return
            in_order(node.left)
            buffer.append(node.val)
            in_order(node.right)

        in_order(root)

        def build_BST(lo: int, hi: int) -> Optional[TreeNode]:
            if lo > hi:
                return None
            mid = lo + ((hi - lo) // 2)
            return TreeNode(buffer[mid], build_BST(lo, mid - 1), build_BST(mid + 1, hi))

        return build_BST(0, len(buffer) - 1)

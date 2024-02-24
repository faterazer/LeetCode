import bisect
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def closestNodes(self, root: Optional[TreeNode], queries: List[int]) -> List[List[int]]:
        tree = []

        def inorder(node: TreeNode) -> None:
            if node:
                inorder(node.left)
                tree.append(node.val)
                inorder(node.right)
        
        inorder(root)

        res = []
        for query in queries:
            i = bisect.bisect_left(tree, query)
            max_val = tree[i] if i < len(tree) else -1
            if i == len(tree) or tree[i] != query:
                i -= 1
            min_val = tree[i] if i >= 0 else -1
            res.append([min_val, max_val])
        return res

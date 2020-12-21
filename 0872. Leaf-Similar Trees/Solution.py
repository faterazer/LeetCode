import itertools


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def nextLeaf(root: TreeNode) -> int:
            if not root:
                return None
            if not root.left and not root.right:
                yield root.val
            yield from nextLeaf(root.left)
            yield from nextLeaf(root.right)

        return all(a == b for a, b in itertools.zip_longest(nextLeaf(root1), nextLeaf(root2)))

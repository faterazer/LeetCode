class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        if not original or original == target:
            return cloned
        r = self.getTargetCopy(original.left, cloned.left, target)
        if r:
            return r
        else:
            return self.getTargetCopy(original.right, cloned.right, target)

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if not t:
            return ''
        elif not t.left and not t.right:
            return str(t.val)
        elif not t.right:
            return '{}({})'.format(t.val, self.tree2str(t.left))
        else:
            return '{}({})({})'.format(t.val, self.tree2str(t.left), self.tree2str(t.right))

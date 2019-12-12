class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def hasPathSum_MK1(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        if not root.left and not root.right:
            return root.val == sum
        sum -= root.val
        return self.hasPathSum_MK1(root.left, sum) or self.hasPathSum_MK1(root.right, sum)

    def hasPathSum_MK2(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False

        stack = [(root, root.val)]
        while stack:
            node, curr_sum = stack.pop()
            if not node.left and not node.right and curr_sum == sum:
                return True
            if node.right:
                stack.append((node.right, curr_sum + node.right.val))
            if node.left:
                stack.append((node.left, curr_sum + node.left.val))
        return False

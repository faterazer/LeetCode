from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def iterNext(stack: List[TreeNode]):
            if not stack:
                return
            node = stack.pop().right
            while node:
                stack.append(node)
                node = node.left

        stack1, stack2 = [], []
        while root1:
            stack1.append(root1)
            root1 = root1.left
        while root2:
            stack2.append(root2)
            root2 = root2.left
        res = []
        while stack1 or stack2:
            if not stack2 or (stack1 and stack1[-1].val <= stack2[-1].val):
                res.append(stack1[-1].val)
                iterNext(stack1)
            else:
                res.append(stack2[-1].val)
                iterNext(stack2)
        return res

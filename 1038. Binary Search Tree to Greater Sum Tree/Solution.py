class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def bstToGst_MK1(self, root: TreeNode) -> TreeNode:
        '''
        Recursion 递归
        Time complexity: O(n)
        Space complexity: O(n)
        '''
        def inOrder(root: TreeNode, preSum: int) -> int:
            if not root:
                return preSum
            root.val += inOrder(root.right, preSum)
            return inOrder(root.left, root.val)
        inOrder(root, 0)
        return root

    def bstToGst_MK2(self, root: TreeNode) -> TreeNode:
        '''
        Iteration with a Stack 迭代
        Time complexity: O(n)
        Space complexity: O(n)
        '''
        stack = []
        preSum = 0
        p = root
        while stack or p:
            while p:
                stack.append(p)
                p = p.right
            p = stack.pop()
            p.val += preSum
            preSum = p.val
            p = p.left
        return root

    def bstToGst_MK3(self, root: TreeNode) -> TreeNode:
        '''
        Reverse Morris In-order Traversal 反转中序 Morris 遍历
        Time complexity: O(n)
        Space complexity: O(1)
        '''
        def getSuccessor(node: TreeNode) -> TreeNode:
            succ = node.right
            while succ.left and succ.left != node:
                succ = succ.left
            return succ

        preSum = 0
        p = root
        while p:
            if not p.right:
                p.val += preSum
                preSum = p.val
                p = p.left
            else:
                succ = getSuccessor(p)
                if not succ.left:
                    succ.left = p
                    p = p.right
                else:
                    succ.left = None
                    p.val += preSum
                    preSum = p.val
                    p = p.left
        return root

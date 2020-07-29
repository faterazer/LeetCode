class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def convertBST_MK1(self, root: TreeNode) -> TreeNode:
        self.inOrder(root, 0)
        return root

    def inOrder(self, root: TreeNode, preSum: int) -> int:
        if not root:
            return preSum
        right = self.inOrder(root.right, preSum)
        root.val += right
        return self.inOrder(root.left, root.val)

    def convertBST_MK2(self, root: TreeNode) -> TreeNode:
        '''
        Iteration with a Stack 迭代方法
        Time complexity: O(n)
        Space complexity: O(n)
        '''
        preSum = 0
        stack = []
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

    def convertBST_MK3(self, root: TreeNode) -> TreeNode:
        '''
        Reverse Morris In-order Traversal 反转中序 Morris 遍历
        Time complexity: O(n)
        Space complexity: O(1)
        '''
        preSum = 0
        p = root
        while p:
            if not p.right:
                p.val += preSum
                preSum = p.val
                p = p.left
            else:
                succ = self.getSuccessor(p)
                if not succ.left:
                    succ.left = p
                    p = p.right
                else:
                    succ.left = None
                    p.val += preSum
                    preSum = p.val
                    p = p.left
        return root

    def getSuccessor(self, root: TreeNode) -> TreeNode:
        succ = root.right
        while succ.left and succ.left != root:
            succ = succ.left
        return succ

from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal_MK1(self, root: Optional[TreeNode]) -> List[int]:
        '''
        Iterating method using Stack
        Time complexity: O(n)
        Space complexity: O(n)
        '''
        res = []
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            res.append(root.val)
            root = root.right
        return res

    def inorderTraversal_MK2(self, root: Optional[TreeNode]) -> List[int]:
        '''
        Morris Traversal
        Time complexity: O(n)
        Space complexity: O(1)
        '''
        def getSuccessor(root: TreeNode) -> TreeNode:
            succ = root.left
            while succ.right and succ.right != root:
                succ = succ.right
            return succ

        res = []
        while root:
            if root.left:
                succ = getSuccessor(root)
                if succ.right == root:
                    succ.right = None
                    res.append(root.val)
                    root = root.right
                else:
                    succ.right = root
                    root = root.left
            else:
                res.append(root.val)
                root = root.right
        return res

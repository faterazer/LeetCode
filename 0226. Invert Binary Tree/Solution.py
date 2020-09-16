from collections import deque


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def invertTree_MK1(self, root: TreeNode) -> TreeNode:
        '''
        Recursive
        '''
        if not root:
            return None
        root.left, root.right = self.invertTree_MK1(
            root.right), self.invertTree_MK1(root.left)
        return root

    def invertTree_MK2(self, root: TreeNode) -> TreeNode:
        '''
        Iterative
        '''
        if not root:
            return None
        
        queue = deque()
        queue.append(root)
        while queue:
            t = queue.popleft()
            t.left, t.right = t.right, t.left
            if t.left:
                queue.append(t.left)
            if t.right:
                queue.append(t.right)
        return root

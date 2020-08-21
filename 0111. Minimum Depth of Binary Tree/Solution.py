from collections import deque


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def minDepth_MK1(self, root: TreeNode) -> int:
        '''
        DFS
        '''
        if not root:
            return 0
        if not root.left:
            return self.minDepth_MK1(root.right) + 1
        if not root.right:
            return self.minDepth_MK1(root.left) + 1
        return min(self.minDepth_MK1(root.left), self.minDepth_MK1(root.right)) + 1

    def minDepth_MK2(self, root: TreeNode) -> int:
        '''
        BFS
        '''
        if not root:
            return 0
        
        deq = deque([(root, 1)])
        while deq:
            node, depth = deq.popleft()
            if not node.left and not node.right:
                return depth
            if node.left:
                deq.append((node.left, depth + 1))
            if node.right:
                deq.append((node.right, depth + 1))
